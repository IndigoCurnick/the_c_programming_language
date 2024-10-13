#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

static unsigned hash(char *s);
static struct nlist *lookup(char *s);
static struct nlist *install(char *name, char *defn);
static void undef(char *name);

void exercise_6_5()
{

    install("TEST", "test");
    install("ANOTHER", "test");

    undef("ANOTHER");

    struct nlist *p = lookup("ANOTHER");

    if (p == NULL)
    {
        printf("Successfully deleted\n");
    }
    else
    {
        printf("Not deleted\n");
    }
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

static void undef(char *name)
{

    struct nlist *np;

    struct nlist *prev;
    unsigned hash_val = hash(name);

    for (np = hashtab[hash_val], prev = NULL;
         np != NULL;
         prev = np, np = np->next)
    {

        if (strcmp(name, np->name) == 0)
        {

            free(np->name);
            free(np->defn);

            if (prev == NULL)
            {
                hashtab[hash_val] = np->next;
            }
            else
            {
                prev->next = np->next;
            }
            free(np);
            return;
        }
    }
}