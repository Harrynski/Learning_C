
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int values[] = {1, 3, 5, 7, 9, 11, 17};
    int n = sizeof values / sizeof values[0];
    int x = 5;

    printf("%d found at index %d\n", x, binsearch(x, values, n));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) 
    {
        mid = (low+high)/2;
        if (x < v[mid])
        {
            printf("x = %d; mid = %d, v[mid]=%d\n", x, mid, v[mid]);
            printf("moving high to mid-1\n");
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            printf("x = %d; mid = %d, v[mid]=%d\n", x, mid, v[mid]);
            printf("moving low to mid+1\n");
            low = mid + 1;
        }
        else /* found match */
            return mid;
    }
    return -1;
}
