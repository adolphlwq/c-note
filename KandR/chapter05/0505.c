/* page 89 5.5 Character Pointer and Function */
#include <stdio.h>

/* page 90 my_strcpy: copy characters of t to s */
void my_strcpy(char *s, char *t)
{
    int i;
    i = 0;

    while((s[i] = t[i]) != '\0')
        i++;
}

/* my_strcpy2: version 2 using pointer */
void my_strcpy2(char *s, char *t)
{
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

/* my_strcpy3: version 3 */
void my_strcpy3(char *s, char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

/* my_strcpy4: version 4 */
void my_strcpy4(char *s, char *t)
{
    while((*s++ = *t++))
        ;
}

/* my_strcmp: compare s and t by alphabetal */
int my_strcmp(char *s, char *t)
{
    int i;
    
    for(i=0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;
    
    return s[i] - t[i];
}

/* my_strcmp: version 2 */
int my_strcmp2(char *s, char *t)
{
    for(; *s == *t; s++, t++)
        if(*s == '\0')
            return 0;

    return *s - *t;
}

void main(void)
{
    // char s[] = "";
    // char t[] = "AdolphLWQ";
    // my_strcpy4(s, t);
    // printf("s is %s\n", s);

    printf("result is %d\n", my_strcmp2("abc", "ab"));
}