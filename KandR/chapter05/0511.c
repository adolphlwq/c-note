/* page 102 5.11 Pointers to Pointers 
    Usage: gcc 0511.c 0504.c        */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "chapter05.h"
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int my_getline(char *s, int lim);

void my_qsort(void *lineptr[], int left, int right,
                int (*comp)(void *, void *));
int numcmp(char *, char *);

/* my_qsort: 以递增顺序对v[left]...v[right]进行排序 */
void my_qsort(void *v[], int left, int right,
                int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;

    for(i=left+1; i<=right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    my_qsort(v, left, last-1, comp);
    my_qsort(v, last+1, right, comp);
}

/* swap: swap v[i] and v[j] */
void swap(void *v[], int i, int j){
    void *tmp;

    tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

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

/* writelines: write lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i=0; i<nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* numcmp: 按数值比较字符串s1和s2的大小 */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1<v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
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

/* 对输入的文本排序 */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        my_qsort((void **) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? (numcmp) : strcmp));

        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }
}