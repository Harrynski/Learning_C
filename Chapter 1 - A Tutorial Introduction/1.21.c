// Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for entab. When
// either a tab or a single blank would suffice to reach a tab stop, which should be given
// preference?


# include <stdio.h>
# define MAXLINE 1000
# define TABSPACES 4
# define IN 1
# define OUT 0

int get_line(char line[], int maxlength);
void entab(char to[], char from[]);

int main(void){
    char line[MAXLINE], new_line[MAXLINE];
    int len;
    while((len = get_line(line, MAXLINE))>0){
        entab(new_line, line);
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
void entab(char to[], char from[])
{
    int i = 0;
    int j = 0;
    int column = 0;

    while (from[i] != '\0' && from[i] != '\n')
    {
        if (from[i] == ' ')
        {
            int end_column = column;

            /* Find where this run of blanks ends. */
            while (from[i] == ' ')
            {
                end_column++;
                i++;
            }

            /* Reach that column using the fewest characters. */
            while (column < end_column)
            {
                int spaces_to_tab = TABSPACES - (column % TABSPACES);

                if (spaces_to_tab > 1 && column + spaces_to_tab <= end_column)
                {
                    to[j++] = '\t';
                    column += spaces_to_tab;
                }
                else
                {
                    to[j++] = ' ';
                    column++;
                }
            }
        }
        else
        {
            to[j++] = from[i];

            if (from[i] == '\t')
                column += TABSPACES - (column % TABSPACES);
            else
                column++;

            i++;
        }
    }

    to[j] = '\0';
}