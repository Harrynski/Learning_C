// Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the
// location.)

int any(char c, char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;

    return 0;
}

int any_2(char s1[], char s2[])
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
        if (any(s1[i], s2))
            return i;

    return -1;
}