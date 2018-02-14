/*
a2_p1.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,i=0,count=0;
    double *arr;
    double *ptr;
    scanf("%d",&n);
    arr=(double *) malloc(sizeof(double)*n); 
    ptr=arr;
    for(i=0;i<n;i++)
    {
        scanf("%lf",&arr[i]);
    }
    while(1)
    {
        if ((int)*ptr-*ptr==0) //if you reach an integer, break
        {
            break;
        }
        ptr++; //navigating array using pointer arithmetic
    }
    count=ptr-arr; 
    printf("Before the first integer: %d elements\n",count);
}