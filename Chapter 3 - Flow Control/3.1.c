// Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside.) Write a version with only one test inside the loop and measure
// the difference in run-time.


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int values[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof values / sizeof values[0];
    int x = 7;

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
            high = mid - 1;
        else (x >= v[mid])
            low = mid ;
        else /* found match */
            return mid;
    }
    return -1;
}
