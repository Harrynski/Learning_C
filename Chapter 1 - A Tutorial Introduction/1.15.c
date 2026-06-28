/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/

#include <stdio.h>
int temperatureConversion(int fahr);

int main(){
    int lower, upper, step, fahr;
   lower = 0; upper = 300; step = 20; /* lower limit of temperature scale */
    fahr = lower;
    while (fahr <= upper) {
        printf("%d\t%d\n", fahr, temperatureConversion(fahr));
        fahr = fahr + step;
    }
}
int temperatureConversion(int fahr)
{
    int  celsius;
 
        celsius = 5 * (fahr-32) / 9;
        return celsius;
}