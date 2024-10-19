#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 1000

void exercise_7_6(int argc, char *argv[])
{
    FILE *fp1, *fp2;

    if (argc != 2)
    {
        printf("Must specify two files");
        return;
    }

    fp1 = fopen(argv[0], "r");
    if (fp1 == NULL)
    {
        printf("File `%s` not found", argv[0]);
    }

    fp2 = fopen(argv[1], "r");
    if (fp2 == NULL)
    {
        printf("File `%s` not found", argv[1]);
    }

    char buf1[MAXBUF];
    char buf2[MAXBUF];

    int i = 0;

    while (fgets(buf1, sizeof(buf1), fp1) != NULL && fgets(buf2, sizeof(buf2), fp2) != NULL)
    {
        if (strcmp(buf1, buf2))
        {
            printf("Files differ on line `%d`\n", i);
            return;
        }

        i++;
    }

    printf("Files identical up to line %d (where one of them ended)\n", i);
}