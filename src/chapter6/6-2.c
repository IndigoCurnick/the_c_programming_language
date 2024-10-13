#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE 1000

static struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

static int getword(char *, int);
static int getch(void);
static void ungetch(int);
static struct tnode *addtree(struct tnode *, char *, int);
static void treeprint(struct tnode *);
static struct tnode *talloc(void);
static char *my_strdup(char *);

static char buffer[BUFSIZE];
static int buffer_pos = 0;

void exercise_6_2(int argc, char *argv[])
{

    int limit = 6;

    if (argc >= 1)
    {
        limit = atoi(argv[0]);
    }

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word, limit);
        }
    }

    treeprint(root);
}

static int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
    {
        ;
    }

    // Skip comments
    if (c == '/')
    {
        int tmp = getch();
        if (tmp == '/')
        {
            while (getch() != '\n')
            {
                continue;
            }
        }
        else
        {
            ungetch(tmp);
        }
    }

    // Skip strings
    if (c == '"')
    {
        while (getch() != '"')
        {
            ;
        }
    }

    // Skip preprocessor
    if (c == '#')
    {
        while (getch() != '\n')
        {
            ;
        }
    }

    if (c != EOF)
    {
        *w++ = c;
    }

    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

static int getch(void)
{
    return (buffer_pos > 0) ? buffer[--buffer_pos] : getchar();
}

static void ungetch(int c)
{
    if (buffer_pos >= BUFSIZE)
    {
        printf("ungetch: too many chars");
    }
    else
    {
        buffer[buffer_pos++] = c;
    }
}

static struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

static char *my_strdup(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1);

    if (p != NULL)
    {
        strcpy(p, s);
    }

    return p;
}

static void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

static struct tnode *addtree(struct tnode *p, char *w, int limit)
{
    int cond;

    char w_lim[MAXWORD];

    int i = 0;
    while (*(w + i) != '\0' && i < limit)
    {
        w_lim[i] = *(w + i);
        i++;
    }

    w_lim[i] = '\0';

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w_lim);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w_lim, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w, limit);
    }
    else
    {
        p->right = addtree(p->right, w, limit);
    }

    return p;
}