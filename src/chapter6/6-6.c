#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101
#define MAXWORD 100
#define BUFSIZE 1000

static unsigned hash(char *s);
static struct nlist *lookup(char *s);
static struct nlist *install(char *name, char *defn);
static int getword(char *word, int lim);
static int getch(void);
static void ungetch(int c);

static char buffer[BUFSIZE];
static int buffer_pos = 0;
static struct nlist *hashtab[HASHSIZE];

void exercise_6_6()
{

    char word[MAXWORD];
    int w = getword(word, MAXWORD);
    char name[MAXWORD];
    char value[MAXWORD];
    int defining = 0;

    while (w != EOF)
    {
        if (strcmp(word, "#define"))
        {
            defining = 1;
            w = getword(word, MAXWORD);
            continue;
        }

        if (defining == 1)
        {
            strcpy(name, word);
            defining = 2;
            w = getword(word, MAXWORD);
            continue;
        }

        if (defining == 2)
        {
            strcpy(value, word);
            w = getword(word, MAXWORD);
            continue;
        }

        if (w == '\n' && defining == 2)
        {
            install(name, value);
            defining = 0;
        }

        w = getword(word, MAXWORD);
    }

    printf("Now try getting your defined words back\n");
}

static unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

static struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
        {
            return np;
        }
    }

    return NULL;
}

static struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
        {
            return NULL;
        }

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
    {
        free((void *)np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }

    return np;
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