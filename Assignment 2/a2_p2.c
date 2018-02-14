/*
a2_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

const int maxsize=100;

int main()
{
    int i=0,a=0,b=0,subSize=0,size=0, count=0;
    int noerror=1;
    char myString[maxsize+1];
    char *mySubstring;

    for(i=0;i<maxsize+1;i++)
    {
        scanf("%c",&myString[i]);
        if (myString[i]=='\n')
        {
            break;
        }
    }
 
    size=i;

    scanf("%d",&a);
    scanf("%d",&b);

    //Checking for errors

    if(a<0)
    {
        printf("The first position is negative!\n");
        noerror=0;
    }
    if(a>size-1)
    {
        printf("The first position is higher than the last position!\n");
        noerror=0;
    }


    if(b<0)
    {
        printf("The second position is negative!\n");
        noerror=0;
    }
    if(b>size-1)
    {
        printf("The second position is higher than the last position!\n");
        noerror=0;
    }

    if(noerror==0){exit(1);}

    subSize=abs(b-a)+1; //b can be less than, equal to, or greater than a. doesnt matter
    mySubstring=(char *) malloc(sizeof(char)*subSize); 
    if (mySubstring==NULL){exit(1);}
    i=0;
    if (a<=b)
    {
        count=a;
        for (i=0;i<subSize;i++)
        {
            mySubstring[i]=myString[count];

            if (count==b)
            {
                break;
            }
            count++;
        }
    }
    if (a>b)
    {
        count=b;
        for (i=0;i<subSize;i++)
        {
            mySubstring[i]=myString[count]; 
            
            if (count==a)
            {
                break;
            }
            count++;
        }
    }

    printf("Result of substring(%d, %d): ",a,b);
    i=0;
    for (i=0;i<subSize;i++)
    {
        printf("%c",mySubstring[i]);
    }
    printf("\n");
    free(mySubstring);
    return 0;


    
}