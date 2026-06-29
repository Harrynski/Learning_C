Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.

The function squeeze(s,c), which removes all occurrences
of the character c from the string s.
/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

I should probably consider:
/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

// Solution:

void squeeze_2(char s1[], char s2[])
{
    int i, j, k, c;
    for (k=0; s2[k] != '\0'; k++){
        c = s2[k];
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != c)
                s1[j++] = s[i];
        s1[j] = '\0';
    }
}
