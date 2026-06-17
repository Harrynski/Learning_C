/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/

# include <stdio.h>
# define MAXLINE 1000
int get_line(char line[], int maxlength);
int clean_line(char from[]);

int main(){
    char line[MAXLINE];
    int len, new_len, i;
    char line_fixed[MAXLINE];
    while((len = get_line(line, MAXLINE))>0){
        new_len = clean_line(line);
        if (new_len> 0){
            printf("%s\n", line);
            // for (i=0; i< new_len-1; i++)
            //     printf("%c",line_fixed[i]);
            }
    }
}

int get_line(char line[], int maxlength){
    int i = 0;
    int c;
    for(i=0; i<maxlength-1 && (c = getchar())!= EOF && c != '\n'; i++)
        line[i] = c;
    if (c=='\n')
        line[i] = c;
        i++;
    line[i] = '\0';
    return(i);
}

int clean_line(char line[])
{
    int i;

    i = 0;
    while (line[i] != '\0')
        ++i;

    if (i > 0 && line[i - 1] == '\n')
        --i;

    while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t'))
        --i;

    line[i] = '\0';

    return i;
}