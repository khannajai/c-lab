/*
JTSK-320112
a3_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list List;

struct list
{
    char info;
    List *next;
};

void print_list(List * my_list ) 
{
    while ( my_list != NULL ) 
    {
        printf ("%c " , my_list->info );
        my_list = my_list->next ;
    }
    printf("\n");
}

List * push_front ( List * my_list , char value ) 
{
    List * newel ;
    newel = ( List *) malloc ( sizeof ( List ));
    if ( newel == NULL ) 
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel->info = value ;
    newel->next = my_list ;
    return newel ;
}

List *pull_front(List *my_list)
{
    List * nextelem;
    
    if(my_list!=NULL)
    {
        nextelem=my_list->next;
        free(my_list);
        my_list=nextelem;
    }

    return my_list;


}

List * push_back ( List * my_list , char value ) 
{
    List * cursor , * newel ;
    cursor = my_list ;
    newel = ( List *) malloc ( sizeof (List));
    if ( newel == NULL ) 
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel->info = value;
    newel->next = NULL;
    if ( my_list == NULL )
        return newel;
    while ( cursor->next != NULL )
        cursor = cursor->next;
    cursor->next = newel;
    return my_list;
}

List *insert (List *my_list, char value, int pos)
{
    List *newel, *listr;
    int i=0;
    listr=my_list;
    newel = ( List *) malloc ( sizeof (List));
    if ( newel == NULL ) 
    {
        printf (" Error allocating memory \n");
        return my_list ;
    }
    newel->info = value;
    newel->next = NULL;
    while(1)
    {
        if((listr)==NULL || pos<0)
        {
            printf("Invalid position!\n");
            break;
        }
        //if the specified position is i+1, place new element there
        if (pos==i+1)
        {
            newel->next=listr->next;
            listr->next=newel;
            break;
        }
        //using listr and i to iterate through list
        listr=listr->next; 
        i++;
    }
    return my_list;
}

List *reverse(List *my_list)
{
    if (my_list->next==NULL || my_list==NULL)
    {
        return my_list;
    }
    List *cursor1, *cursor2, *cursor3;
    cursor1=my_list;
    cursor2=cursor1->next;
    cursor3=cursor2->next;
    while(1)
    {
        cursor2->next=cursor1;
        cursor1=cursor2;
        if (cursor3==NULL)
        {
            break;
        }
        cursor2=cursor3;
        cursor3=cursor3->next;
    }
    my_list->next=NULL;
    return cursor2;
}

void dispose_list ( List * my_list ) 
{
    List * nextelem;
    while ( my_list != NULL ) 
    {
        nextelem = my_list->next;
        free(my_list);
        my_list=nextelem;
    }
}


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