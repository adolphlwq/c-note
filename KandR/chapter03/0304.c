/* page 48 switch statement */
#include <stdio.h>

void count_switch(){
    int c, i, nw, no, ndigits[10];
    nw=no=0;
    for(i=0;i<10;i++){
        ndigits[i]=0;
    }

    while((c=getchar())!=EOF){
        switch(c){
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigits[c-'0']++;
                break;
            case ' ': case '\t': case '\n':
                nw++;
                break;
            default:
                no++;
                break;
        }
    }

    printf("digits is :");
    for(i=0;i<10;i++){
        printf(" %d", ndigits[i]);
    }

    printf(", white space = %d, other = %d\n", nw, no);
}

/* page 49 exercise 3.2 */
/* escape: expand newline and tab into visible sequences
    while copying the string t to s */
void escape(char s[], char t[]){
    int i, j;
    for(i=j=0;t[i]!='\0';i++){
        switch(t[i]){
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            case '\t':
                s[j++]='\\';
                s[j++]='t';
                break;
            default:
                s[j++]=t[i];
                break;
        }
    }

    s[j]='\0';
}

/* unescape: convert escape sequences into real characters
    while copying the string t to s */
void unescape(char s[], char t[]){
    int i, j;

    for(i=j=0; t[i]!='\0';i++){
        if(t[i]!='\\')
            s[j++]=t[i];
        else{
            switch(t[++i]){
            case 'n':
                s[j++]='\n';
                break;
            case 't':
                s[j++]='\t';
                break;
            default:
                s[j++]='\\';
                s[j++]=t[i++];
                break;
            }
        }
    }

    s[j]='\0';
}

/* unescape2: method 2 */
void unescape2(char s[], char t[]){
    int i, j;
    for(i=j=0;t[i]!='\0';i++){
        switch(t[i]){
        case '\\':
            switch(t[++i]){
            case 'n':
                s[j++]='\n';
                break;
            case 't':
                s[j++]='\t';
                break;
            default:
                s[j++]='\\';
                s[j++]=t[i];
                break;
            }
        default:
            s[j++]=t[i];
            break;
        }
    }
}

void main(void){
    // count_switch();
    char t[] = "abd d\n";
    char s[]="";
    escape(s, t);
    printf("%s\n", s);
}