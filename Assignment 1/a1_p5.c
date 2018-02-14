/*
a1_p5.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void itobin(unsigned int n, int low);
int findPositionOfMSB (unsigned int n); 

int main()
{
    unsigned int n;        
    scanf("%u",&n);
    printf("The backwards binary representation is: ");
    itobin(n, findPositionOfMSB(n));
}

void itobin(unsigned int n, int low) //takes the number and the position of the most significant bit
{
    int i;
    for(i=0;i<=low;i++)
    {
        if(n & 1 << i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");

}

int findPositionOfMSB (unsigned int n) //finds the position of the most significant bit and returns it as an int
{
    int high=31, low=0;
 
    while (high - low > 1)
    {
        int mid = (high+low)/2;
        int maskHigh = (1 << high) - (1 << mid);
        if ((maskHigh & n) > 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}