#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE 1000
#define MAXLINES 100

static struct tnode
{
    char *word;
    int count[MAXLINES];
    int counter;
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

static int global_line_counter = 0;

void exercise_6_3()
{

    struct tnode *root;
    char word[MAXWORD];

    int line_num = 0;
    int w = getword(word, MAXWORD);

    root = NULL;
    while (w != EOF)
    {
        if (w == '\n')
        {
            line_num += 1;
        }
        else if (isalpha(word[0]))
        {
            root = addtree(root, word, line_num);
        }

        w = getword(word, MAXWORD);
    }

    treeprint(root);
}

static int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))
    {
        if (c == '\n') // If newline is encountered
        {
            return '\n'; // Report the newline
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
    struct tnode *t = (struct tnode *)malloc(sizeof(struct tnode));
    t->counter = 0;
    return t;
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

        printf("%s: ", p->word);

        for (int i = 0; i < p->counter; i++)
        {
            printf(" %d ", p->count[i]);
        }
        printf("\n");
        treeprint(p->right);
    }
}

static struct tnode *addtree(struct tnode *p, char *w, int line_count)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w);
        p->left = p->right = NULL;
        p->count[p->counter] = line_count;
        p->counter += 1;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count[p->counter] = line_count;
        p->counter += 1;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w, line_count);
    }
    else
    {
        p->right = addtree(p->right, w, line_count);
    }

    return p;
}