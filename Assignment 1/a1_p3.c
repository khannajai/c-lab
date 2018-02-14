/*
a1_p3.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#define SUM(A,B,C) (A)+(B)+(C)
#define MAX(A,B,C) ((A)>(B)?((A)>(C)?(A):(C)):((B)>(C)?(B):(C)))
#define MIN(A,B,C) ((A)<(B)?((A)<(C)?(A):(C)):((B)<(C)?(B):(C)))
#define EXPR(A,B,C) (float)((SUM(A,B,C)+MAX(A,B,C)))/(float)(MIN(A,B,C))

int main()
{
    int a=0,b=0,c=0;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("The value of the expression is: %.6f\n", EXPR(a,b,c));

    return 0;
}