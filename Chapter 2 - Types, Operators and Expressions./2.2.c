// Exercise 2-2. Write a loop equivalent to the for loop below without using && or ||.

// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;


#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    int c, i;
    char s[MAXLINE];
    int lim = MAXLINE;

    for (i = 0; i < lim - 1; ++i) {
        c = getchar();

        if (c == '\n')
            break;

        if (c == EOF)
            break;

        s[i] = c;
    }

    s[i] = '\0';

    printf("%s\n", s);

    return 0;
}
