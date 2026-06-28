// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?


# include <stdio.h>
# define MAXLINE 1000
# define TABSPACES 4
int get_line(char line[], int maxlength);
void detab(char to[], char from[]);

int main(void){
    char line[MAXLINE], new_line[MAXLINE];
    int len;
    while((len = get_line(line, MAXLINE))>0){
        detab(new_line, line);
        printf("%s", new_line);
        printf("\n");
        // if (new_len> 0){
        //     printf("%s\n", line);
        //     // for (i=0; i< new_len-1; i++)
        //     //     printf("%c",line_fixed[i]);
        //     }
    }
    return 0;
}

int get_line(char line[], int maxlength){
    int i = 0;
    int c;
    for(i=0; i<maxlength-1 && (c = getchar())!= EOF && c != '\n'; i++)
        line[i] = c;
    if (c=='\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return(i);
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void detab(char to[], char from[])
{
    int i, j;
    i = j = 0;
    while (from[i] != '\0' && from[i] != '\n')
    {
    if (from[i] == '\t') {
        int spaces = TABSPACES - (j % TABSPACES);

        while (spaces-- > 0)
            to[j++] = ' ';
    }
        else
        {
            to[j] = from[i];
            j++;
        }
        ++i;
    }
    to[j] = '\0';
}