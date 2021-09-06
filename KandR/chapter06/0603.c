/* page 115 6.3 Arrays of Structures */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "chapter06.h"

#define NKEYS (sizeof keytab / sizeof(struct key))
// #define NKEYS = (sizeof keytab / sizeof keytab[0])

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    /* ...... */
    {"void", 0}
};

int getword(char *, int);
int getword_ex0601(char *word, int lim);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while(getword_ex0601(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    
    for(n=0; n<NKEYS;n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    
    return 0;
}

/* binsearch: search word in keytab */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;
    while(low<=high){
        mid = (low+high)/2;
        if((cond=strcmp(word, tab[mid].word)) < 0)
            high = mid-1;
        else if(cond>0)
            low = mid+1;
        else
            return mid;
    }

    return -1;
}

/* getword: read next word fron input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(; --lim>0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 1000
static char buf[BUFSIZE];
static int bufp = 0;       /* next position in buf */

int getch(void){
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getword_ex0601: get next word or character from input */
int getword_ex0601(char *word, int lim)
{
    int c, d, comment(void);
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    if(isalpha(c) || c == '_' || c == '#'){
        for(; --lim > 0; w++)
            if(!isalnum(*w = getch()) && *w != '_'){
                ungetch(*w);
                break;
            }
    }else if(c == '\'' || c == '"'){
        for(; --lim > 0; w++)
            if((*w = getch()) == '\\')
                *++w = getch();
            else if(*w == c){
                w++;
                break;
            }else if(*w == EOF)
                break;
    }else if (c == '/')
        if((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment(void)
{
    int c;
    while((c = getch()) != EOF)
        if(c == '*')
            if((c = getch()) == '/')
                break;
            else
                ungetch(c);
    return c;
}