
/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/
#include <stdio.h>
#define STRING "Fahrenheit-Celsius table"

/* print Fahrenheit-Celsius table */
int main()
    {
        int c, blank, tab, newline;
        blank = tab = newline = 0;
        while( (c=getchar()) != EOF)
        {
            if(c == ' ')
                blank++ ;
            if(c == '\t')
                tab++   ;
            if(c == '\n')
                newline++;
        }
        printf("blank: %d, tab: %d, newline: %d\n", blank, tab, newline);
        
    }


// #include <stdio.h>
// /* count lines in input */
// int main()

// {
// int c, nl;
// nl = 0;
// while ((c = getchar()) != EOF)
// if (c == '\n')
// ++nl;
// printf("%d\n", nl);
// }