/* page 153 exercise 8.1 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFSIZE 1024

void error(char *fmt, ...);

/* cat: concatenate files - read/write/open/close */
void main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);

    if(argc == 1)
        filecopy(0, 1);
    else
        while(--argc > 0)
            if((fd = open(*++argv, O_RDONLY)) == -1)
                error("cat: can't open %s", *argv);
            else{
                filecopy(fd, 1);
                close(fd);
            }
}

/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZE];

    while((n = read(ifd, buf, BUFSIZE)) > 0)
        if(write(ofd, buf, n) != n)
            error("cat: write error");
}

void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}