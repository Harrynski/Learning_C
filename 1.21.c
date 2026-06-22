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

/* copy: copy 'from' into 'to'; assume to is big enough */
void entab(char to[], char from[])
{
    int i, j, status, space_count;
    i = j = space_count = 0;
    status = OUT;

    while (from[i] != '\0' && from[i] != '\n')
    {
        if (status == IN && from[i] != ' ')
        {
            status = OUT;
            int spaces_till_next_tab = TABSPACES - (j % TABSPACES);
            int tabs_in_remaining_space = (space_count-spaces_till_next_tab)/TABSPACES;
            int remainder = (space_count-spaces_till_next_tab)%TABSPACES;

            if (spaces_till_next_tab < space_count)
            {
                to[j] = '\t';
                j++;
            }
            // if (tabs_in_remaining_space>0)
            // {
            while(tabs_in_remaining_space>0)
            {
                to[j] = '\t';
                j++;
                tabs_in_remaining_space--;
            }
            while(remainder>0)
            {
                to[j] = ' ';
                j++;
                remainder--;
            }
            space_count = 0;

        }
        if (from[i] == ' ')
        {
            status = IN;
            space_count++;
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