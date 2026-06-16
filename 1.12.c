/*Exercise 1-12. Write a program that prints its input one word per line.*/

#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
int main(){
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("\n");
        }
    }