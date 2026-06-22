#include <stdio.h>

#define MAXLINE 1000
#define CUT_SIZE 5

int get_line(char string[], int limit);
int find_last_blank_index(int n, int current_index, char string[]);
int cut_string(int n, int current_index, char string[]);

int main(void)
{
    int current_index;
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        current_index = 0;

        while (line[current_index] != '\0' &&
               line[current_index] != '\n') {
            current_index =
                cut_string(CUT_SIZE, current_index, line);
            putchar('\n');
        }
    }

    return 0;
}

int get_line(char string[], int limit)
{
    int c, i;

    for (i = 0;
         i < limit - 1 &&
         (c = getchar()) != EOF &&
         c != '\n';
         ++i) {
        string[i] = c;
    }

    if (c == '\n') {
        string[i++] = c;
    }

    string[i] = '\0';

    return i;
}

int find_last_blank_index(int n, int current_index, char string[])
{
    int i;

    i = current_index + n - 1;

    while (i > current_index) {
        if (string[i] == ' ' || string[i] == '\t') {
            return i;
        }

        --i;
    }

    return -1;  /* no blank found */
}

int cut_string(int n, int current_index, char string[])
{
    int blank_index;
    int end_index;
    int i;

    /* Find the end of this n-character section. */
    end_index = current_index;

    while (end_index < current_index + n &&
           string[end_index] != '\0' &&
           string[end_index] != '\n') {
        ++end_index;
    }

    /*
     * If n characters remain, look for a blank.
     * Otherwise, print the short final section.
     */
    blank_index = -1;

    if (end_index == current_index + n) {
        blank_index =
            find_last_blank_index(n, current_index, string);
    }

    if (blank_index != -1) {
        end_index = blank_index;
    }

    for (i = current_index; i < end_index; ++i) {
        putchar(string[i]);
    }

    if (blank_index != -1) {
        current_index = blank_index + 1;

        /* Skip additional blanks at the fold. */
        while (string[current_index] == ' ' ||
               string[current_index] == '\t') {
            ++current_index;
        }

        return current_index;
    }

    return end_index;
}