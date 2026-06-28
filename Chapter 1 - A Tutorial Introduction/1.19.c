/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.
*/
# include <stdio.h>
# define MAXLINE 1000

int get_line(char line[], int maxlength);
void reverse_string(char s[]);

int main(){

    char s[MAXLINE];
    int len;
    while((len=get_line(s, MAXLINE))>0){
        reverse_string(s);
        printf("%s", s);
        printf("\n");
    }
}

void reverse_string(char s[]){
    int j, c, i=0;
    while (s[i] != '\0')
        ++i;
    i--;

    for(j=0; j<(i-j); j++){
        c = s[j];
        s[j] = s[i-j];
        s[i-j] = c;
    }

}

int get_line(char line[], int maxlength){
    int i = 0;
    int c;
    for(i=0; i<maxlength-1 && (c = getchar())!= EOF && c != '\n'; i++)
        line[i] = c;
    if (c=='\n') {
        //line[i] = c;
        i++;
    }
    line[i] = '\0';
    return(i);
}