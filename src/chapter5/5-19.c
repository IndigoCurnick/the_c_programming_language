#include "chapter5.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum
{
    NAME,
    PARENS,
    BRACKETS,
    ERROR
};

static int gettoken(void);
static int tokentype;
static int prevtoken;

static char token[MAXTOKEN];
static char name[MAXTOKEN];
static char datatype[MAXTOKEN];
static char out[1000];

void exercise_5_19()
{
    int type;
    char tmp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);

        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
            {
                strcat(out, token);
            }
            else if (type == '*')
            {
                if (out[0] == '(' || out[0] == '[')
                {
                    sprintf(tmp, "(*%s)", out);
                }
                else
                {
                    sprintf(tmp, "*%s", out);
                }

                strcpy(out, tmp);
            }
            else if (type == NAME)
            {
                sprintf(tmp, "%s %s", token, out);
                strcpy(out, tmp);
            }
            else
            {
                printf("Invalid output: %s\n", token);
            }
        }

        printf("%s\n", out);
    }
}

/* gettoken: return next token */
int gettoken(void)
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']' && (*(p - 1) != '\n');)
            ;
        *p = '\0';
        if ((*(p - 1)) == ']')
            return tokentype = BRACKETS;
        else
            return tokentype = ']';
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }
}
