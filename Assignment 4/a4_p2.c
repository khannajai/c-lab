/*JTSK-320112
a4_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void upper_case(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i]>='a' || s[i]<='z')
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}

void lower_case(char s[]) 
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i]>='A' || s[i]<='Z')
        {
            printf("%c", tolower(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
}

void invert(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else if (isupper(s[i]))
        {
            printf("%c",tolower(s[i]));
        }
        else if(s[i]==' ')
        {
            printf(" ");
        }
    }
    	printf("\n");
}

void exit_program(char s[])
{
    exit(0);
}

int main() 
{
    char my_string[100];
    fgets(my_string, 100, stdin);
    void (*func_array[4])(char s[])= {upper_case, lower_case, invert, exit_program};
    char c;
        while(1)
        {
            scanf("%c", &c);
            getchar();
            func_array[(int)(c)-97](my_string); //using ASCII code for a,b,c,d
        }

    return 0;
}

