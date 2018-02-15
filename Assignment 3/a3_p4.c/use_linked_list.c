/*
JTSK-320112
a3_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    List *my_list=NULL;
    int n=0, p=0;
    char c;
    while(1)
    {
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1:
                scanf("%c",&c);
                getchar();
                my_list=push_back(my_list,c);
                break;
            case 2:
                scanf("%c",&c);
                getchar();
                my_list=push_front(my_list,c);
                break;
            case 3:
                if(my_list==NULL)
                {
                    break;
                }
                else
                {
                    my_list=pull_front(my_list);
                }
                break;
            case 4:
                print_list(my_list);
                break;
            case 5:
                dispose_list(my_list);
                exit(0);
            case 6:
                scanf("%d",&p);
                getchar();
                scanf("%c",&c);
                getchar();
                my_list=insert(my_list, c, p);
                break;
            case 7:
                my_list=reverse(my_list);
                break;

        }
    }
    return 0;
}