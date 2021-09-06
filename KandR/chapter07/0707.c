/* page 144 7.7 Line Input and Output */
#include <stdio.h>
#include <string.h>

char *my_fgets(char *s, int n, FILE *iop)
{
    register int c;
    register char *cs;

    cs = s;
    while(--n>0 && (c=getc(iop)) != EOF)
        if((*cs++ = c) == '\n')
            break;
    *cs = '\0';
    return (c==EOF && cs == s)?NULL : s;
}

int my_fputs(char *s, FILE *iop)
{
    int c;

    while(c = *s++)
        putc(c, iop);
    return ferror(iop)?EOF:2;
}

int my_getline(char *line, int max)
{
    if(fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}

void main()
{
    char line[100];
    while(my_getline(line, 100) > 0)
        printf("%s\n", line);
}