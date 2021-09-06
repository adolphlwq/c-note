/* page 100 */
#include <stdio.h>
#include <string.h>

#include "chapter05.h"

int my_getline(char *line, int max);

/* find: print line match first pattern */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;
    
    if(argc != 2)
        printf("Usage: find pattern\n");
    else
        while(my_getline(line, MAXLINE) > 0)
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
    
    return found;
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