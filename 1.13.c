/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/


# include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main(){
    int c, i, k, state, wordCount;
    int wordOfLengthNCount[30];
    for (i = 0; i < 30; ++i)
        wordOfLengthNCount[i] = 0;
    state = OUT;
    wordCount = 0;
    while((c=getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if (wordCount > 0){
                wordOfLengthNCount[wordCount]++;
                wordCount = 0;
            }
            // printf("word count for the previous one: "),
            // printf(" %d", wordCount),
            // printf("\n");

        }
        else if (state == OUT){
            state = IN;
            wordCount = 0;
        }
        if (state == IN)
            wordCount++;
    if (wordCount > 0)
    wordOfLengthNCount[wordCount]++;

    }
    for (i = 1; i < 10; ++i) {
        printf("Words with %d letters: %d ", i, wordOfLengthNCount[i]);
        for (k = 0; k < wordOfLengthNCount[i]; k++)
            printf("|");
        printf("\n");
    }
        
}