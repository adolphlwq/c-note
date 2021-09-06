/* page 92 exercise 5.5 */
#include <stdio.h>
#include <string.h>

/* my_strncpt: copy n characters from t to s */
void my_strncpy(char *s, char *t, int n)
{
    for(int i=0; i<n && *t != '\0'; i++)
        *s++ = *t++;
    
    *s = '\0';
}

/* my_strncpy2: version 2 */
void my_strncpy2(char *s, char *t, int n)
{
    while(*t && n-- > 0)
        *s++ = *t++;
    
    *s = '\0';
}

/* my_strncat: concatenate n characters of t to the end of s */
void my_strncat(char *s, char *t, int n)
{
    while(*s)
        s++;
    while(*t && n-- > 0)
        *s++ = *t++;
    
    *s = '\0';
}

/* my_strncat2: version 2 */
void my_strncat2(char *s, char *t, int n)
{
    my_strncpy(s + strlen(s), t, n);
}

/* my_strncat3: answer version */
void my_strncat3(char *s, char *t, int n)
{
    // void strncpy(char *s, char *t, int n);
    // int strlen(char *s);

    strncpy(s+strlen(s), t, n);
}

/* my_strncmp: compare at most n characters of t with s */
int my_strncmp(char *s, char *t, int n)
{
    for(; *s == *t; s++, t++)
        if(*s == '\0' || --n <= 0)
            return 0;
    
    return *s - *t;
}

void main(void)
{
    char s[] = "Hi ";
    char t[] = "AdolphLWQ";
    // my_strncpy(s, t, 2);
    // my_strncat2(s, t, 2);
    // printf("%s\n", s);

    printf("%d\n", my_strncmp(s, t, 2));
}