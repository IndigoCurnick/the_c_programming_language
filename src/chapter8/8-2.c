#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PERMS 0666 // RW for owner, group, others
#define BUF_SIZE 1024

static struct iobuf *f_open(const char *name, const char *mode);
static int f_close(struct iobuf *fp);
static void print_file(struct iobuf *fp);

struct iobuf
{
    int fd;       // File descriptor
    int is_read;  // File open for reading
    int is_write; // File open for writing
    int is_unbuf; // Unbuffered if true
    int is_eof;   // End of file reached
    int is_err;   // Error occurred
    char *buf;    // Pointer to buffer
    int buf_size; // Buffer size
};

void exercise_8_2(int argc, char *argv[])
{
    struct iobuf *file_p;

    if (argc != 1)
    {
        write(1, "Error: Did not provide file.\n", 30);
        return;
    }

    if ((file_p = f_open(argv[0], "r")) == NULL)
    {
        write(1, "Error: could not open the file.\n", 33);
        return;
    }
    else
    {
        print_file(file_p);
        f_close(file_p);
    }
}

static struct iobuf *f_open(const char *name, const char *mode)
{
    int fd;
    struct iobuf *fp;

    if ((fp = (struct iobuf *)malloc(sizeof(struct iobuf))) == NULL) // allocate iobuf structure
        return NULL;

    if (*mode == 'r')
    {
        fd = open(name, O_RDONLY, 0);
        fp->is_read = 1;
    }
    else if (*mode == 'w')
    {
        fd = creat(name, PERMS);
        fp->is_write = 1;
    }
    else if (*mode == 'a')
    {
        fd = open(name, O_WRONLY | O_APPEND, 0);
        fp->is_write = 1;
    }
    else
    {
        return NULL; // invalid mode
    }

    if (fd == -1) // check if file open failed
        return NULL;

    fp->fd = fd;
    fp->is_unbuf = 0; // assume buffered by default
    fp->is_eof = 0;
    fp->is_err = 0;
    fp->buf = NULL; // assume no buffer yet

    return fp;
}

static int f_close(struct iobuf *fp)
{
    if (fp == NULL)
        return -1;
    int res = close(fp->fd); // close the file descriptor
    free(fp);                // free the allocated memory
    return res;
}

static void print_file(struct iobuf *fp)
{

    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    // Read the file in chunks of BUF_SIZE and write it to the terminal
    while ((bytes_read = read(fp->fd, buffer, sizeof(buffer))) > 0)
    {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
        {
            perror("write");
            f_close(fp);
            return;
        }
    }

    if (bytes_read == -1)
    { // Error while reading
        printf("File read error\n");
    }
}