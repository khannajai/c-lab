/*
JTSK-320112
a3_p3.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list List;

struct list
{
    int info;
    List *next;
    List *prev;
};

List *head;
List *tail;

void print_list(List * my_list )
{
    while(my_list!=NULL)
    {
        printf("%d ",my_list->info);
        my_list=my_list->next;
    }
    printf("\n");
}

void print_back(List *my_list)
{
    List *ptr;
    ptr=tail;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->prev;
    }
    printf("\n");
}


List *new_node(int x) 
{
	List* newNode;
    newNode = (List*)malloc(sizeof(List));
    if (newNode== NULL ) 
    {
        printf ("Error allocating memory\n");
        return newNode ;
    }
	newNode->info = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

List * push_front ( List * my_list, int n) 
{
    List* newel;
    newel=new_node(n);
    if(my_list==NULL)
    {
        head=newel;
        tail=newel;
        return newel;   
    }
    else
    {
        newel->next=head;
        head->prev=newel;
        head=newel;
    }
    return head;

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

List *remove_el(List *my_list, int n)
{
    List *left, *right, *current;
    current=my_list;
    int element_found=0;
    while(current!=NULL)
    {
        if(current->info==n)
        {
            element_found=1;
            if(current==tail && current==head) //if only one element
            {
                free(current);
                break;
            }
            else if(current==head)//if its a head element of a list>1 make the next element a head
            {
                head=current->next;
                free(current);
                current=head;
                head->prev=NULL;
            }
            else if(current==tail)//if its a tail element of a list>1 make the previous element a tail
            {
                tail=current->prev;
                free(current);
                tail->next=NULL;
                break;
            }
            else//if its a midle element of a list>1 connect the left and right elements
            {
                left=current->prev;
                right=current->next;
                left->next=right;
                right->prev=left;
                free(current);
                current=right;
            }

        }
        else
        {
            current=current->next;
        }
    }
    if (element_found==0)
    {
        printf("The element is not in the list!\n");
    }
    return head;
}

int main()
{
    List *my_list=NULL;
    head=NULL;
    tail=NULL;
    int n=0;
    char c;
    while(1)
    {
        scanf("%c",&c);
        getchar();
        switch(c)
        {
            case 'a':
                scanf("%d",&n);
                getchar();
                my_list=push_front(my_list,n);
                break;
            case 'r':
                scanf("%d",&n);
                getchar();
                my_list=remove_el(my_list,n);
                break;
            case 'b':
                print_back(my_list);
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'q':
                dispose_list(my_list);
                exit(0);
        }
    }
    return 0;
}