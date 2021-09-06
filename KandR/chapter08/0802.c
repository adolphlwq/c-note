/* page 150 Low Level I/O */
#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 1024

void code1()
{
    char buf[BUFSIZE];
    int n;

    while((n = read(0, buf, BUFSIZE)) > 0)
        write(1, buf, n);
}

int getchar1()
{
    char c;
    return (read(0, &c, 1) == 1)?(unsigned char) c:EOF;
}

int getchar2()
{
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    if(n == 0){
        n = read(0, buf, BUFSIZE);
        bufp = buf;
    }

    return (--n >= 0)?(unsigned char) *bufp++:EOF;
}

void main()
{
    int c;
    while((c=getchar2()) != EOF)
        putchar(c);
}