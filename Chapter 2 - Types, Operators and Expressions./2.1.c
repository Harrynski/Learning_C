#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
printf("CHAR_MIN = %d\n", CHAR_MIN);
printf("CHAR_MAX = %d\n", CHAR_MAX);

unsigned char uc = 0;
unsigned short us = 0;
unsigned int ui = 0;
unsigned long ul = 0;

printf("unsigned char max = %u\n", uc - 1);
printf("unsigned short max = %u\n", us - 1);
printf("unsigned int max = %u\n", ui - 1);
printf("unsigned long max = %lu\n", ul - 1);


unsigned int uint_max = ui - 1;

int int_max = uint_max / 2;
int int_min = -int_max - 1;


/* header value */
printf("UINT_MAX from header = %u\n", UINT_MAX);

/* computed value */
printf("UINT_MAX computed    = %u\n", 0U - 1);

return 0;
}