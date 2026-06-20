// Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?


# include <stdio.h>
# define MAXLINE 1000
# define tabspaces 4
int get_line(char line[], int maxlength);
void detab(char to[], char from[]);

int main(){
    char line[MAXLINE], new_line[MAXLINE];
    int len, new_len, i;
    char line_fixed[MAXLINE];
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
    int i, j, k;
    i = j = 0;
    while (from[i] != '\0' && from[i] != '\n')
    {
        if (from[i] == '\t')
        {
            for(k=0; k<tabspaces; k++)
                {
                to[j] = ' ';
                j++;
                }
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