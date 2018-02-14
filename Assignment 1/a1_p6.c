/*
a1_p6.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void uintobin(unsigned int num);

int main()
{
    unsigned int n;        
    scanf("%u",&n);
    printf("The binary representation is: ");
    uintobin(n);
}

void uintobin(unsigned int n)
{
    int mask=32768;   //for highest bit

    while(mask > 0)
    {
    if((n & mask) == 0 )
            printf("0");
    else
            printf("1");
    mask = mask >> 1 ;  // Right Shift
    }
    printf("\n");
}
