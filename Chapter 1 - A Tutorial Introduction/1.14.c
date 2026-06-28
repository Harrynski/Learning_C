/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/


# include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define NCHARS 128 

int main(){
    int c, i;
    int characters[NCHARS];
    for (i = 0; i < NCHARS; ++i){
        characters[i] = 0;}
    // state = OUT;
    // wordCount = 0;
    while((c=getchar()) != EOF){
        characters[c]++;
    //     if (c == ' ' || c == '\n' || c == '\t'){
    //         state = OUT;
    //         if (wordCount > 0){
    //             characters[wordCount]++;
    //             wordCount = 0;
    //         }
    //         // printf("word count for the previous one: "),
    //         // printf(" %d", wordCount),
    //         // printf("\n");

    //     }
    //     else if (state == OUT){
    //         state = IN;
    //         wordCount = 0;
    //     }
    //     if (state == IN)
    //         wordCount++;
    // if (wordCount > 0)
    // characters[wordCount]++;

    // }
    // for (i = 1; i < 10; ++i) {
    //     printf("Words with %d letters: %d ", i, characters[i]);
    //     for (k = 0; k < characters[i]; k++)
    //         printf("|");
    //     printf("\n");
    }
    for (i=1; i<NCHARS; ++i)
        if (characters[i]>0)
            printf("%c @ %d", i, characters[i]),
            printf("\n");

}