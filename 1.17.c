
/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define MAXSTORED 100 /* maximum number of lines to store */
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    int i = 0, j=0; /* index for longlines */
    char line[MAXLINE]; /* current input line */
    char longlines[MAXSTORED][MAXLINE]; /* longest line saved here */
    max = 8;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            copy(longlines[i], line);
            //printf("%s", line);
            i++;
        }
    if (i){
        printf("Lines longer than %d \n", max);
        for (j=0; j<i; j++)
            printf("%s", longlines[j]);
    }
    return 0;
}

/* get_line: read a line into s, return length int get_line(char s[],int lim)
*/
int get_line(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    ++i;
}