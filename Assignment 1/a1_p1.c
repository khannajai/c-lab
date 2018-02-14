/*
a1_p1.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#define PERMUTATION(A,B,C,T) {T temp; temp=(A); (A)=(C); (C)=(B); (B)=temp;} 

int main()
{
    int a=0, b=0, c=0;
    double x=0, y=0, z=0;
    
    //Enter 3 integers
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    //Enter 3 doubles
    scanf("%lf", &x);
    scanf("%lf", &y);
    scanf("%lf", &z);

    PERMUTATION(a,b,c,int);
    PERMUTATION(x,y,z,double);

    printf("After the permutation:\n");
    printf("%d\n%d\n%d\n%.5lf\n%.5lf\n%.5lf\n", a,b,c,x,y,z);

    return 0;
}