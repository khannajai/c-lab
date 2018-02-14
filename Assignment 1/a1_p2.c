/*
a1_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#define THEBIT(C) {if(((C) & 4) == 4){printf("1\n");} else {printf("0\n");} } //using 2^2 as mask with "&" operation

int main()
{
    unsigned char c;

    //Enter a character
    scanf("%c", &c);
    printf("The decimal representation is: %d\n", c);
    printf("The third least significant bit is: ");
    THEBIT(c);


    return 0;
}