#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE 1000
#define MAX_NR_OF_NODES 10000

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
static struct tnode *addtree(struct tnode *, char *);
static void treeprint(struct tnode *);
static struct tnode *talloc(void);
static char *my_strdup(char *);
static int compare_freq(const void *a, const void *b);
static void tree_to_array(struct tnode *arr[], struct tnode *tree_node_p, int *index);
static void my_qsort(void *v[], int left, int right, int (*comp)(const void *, const void *));
static void swap(void *v[], int i, int j);

static char buffer[BUFSIZE];
static int buffer_pos = 0;

static int total_unique_words = 0;

void exercise_6_4()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }

    struct tnode *tree_node_list[MAX_NR_OF_NODES] = {NULL};
    int index = 0;
    tree_to_array(tree_node_list, root, &index);

    my_qsort((void **)tree_node_list, 0, total_unique_words - 1, compare_freq);

    printf("\nWords sorted by frequency:\n");
    for (int i = 0; i < total_unique_words; i++)
    {
        printf("%s: %d\n", tree_node_list[i]->word, tree_node_list[i]->count);
    }
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

static struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
        total_unique_words += 1;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }

    return p;
}

static int compare_freq(const void *a, const void *b)
{
    struct tnode *wa = (struct tnode *)a;
    struct tnode *wb = (struct tnode *)b;
    return wa->count - wb->count; // Sort in descending order of frequency
}

static void tree_to_array(struct tnode *arr[], struct tnode *tree_node_p, int *index)
{
    if (tree_node_p != NULL)
    {
        tree_to_array(arr, tree_node_p->left, index);

        arr[*index] = tree_node_p;
        (*index)++;

        tree_to_array(arr, tree_node_p->right, index);
    }
}

static void my_qsort(void *v[], int left, int right, int (*comp)(const void *, const void *))
{
    int i, last;

    if (left >= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

static void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}