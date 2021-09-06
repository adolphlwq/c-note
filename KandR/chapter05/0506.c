/* page 92 5.6 Pointer Arrays and Pointers to Pointer 
    usage gcc 0506.c 0504.c                          */

#include <stdio.h>
#include <string.h>

#include "chapter05.h"

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(char *lineptr[], int left, int right);

int sort_line()
{
    int nlines;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        my_qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("error: input too big to sort\n");
        return 1;
    }
}

int my_getline(char *, int);
char *alloc(int);

/* readlines: read input line */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = my_getline(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0';     /* remove '\n' */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* readlines_ex57: read input lines */
int readlines_ex57(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;                     /* 内部数组起始地址 */
    char *linestop = linestor + MAXSTOR;    /* 内部数组截止的地方 */

    nlines = 0;
    while((len = my_getline(line, MAXLEN)) >= 0)
        if(nlines >= maxlines || p+len > linestop)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }

    return nlines;
}

/* writelines: write lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i=0; i<nlines; i++)
        printf("%s\n", lineptr[i]);
}

int my_getline(char *s, int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n' ; i++)
        s[i] = c;
    if(c == '\n')
        s[i++] = '\n';
    
    s[i] = '\0';
    return i;
}

void my_qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;

    for(i=left+1; i<=right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, last, left);

    my_qsort(v, last+1, right);
    my_qsort(v, left, last-1);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void main(void)
{
    sort_line();
}