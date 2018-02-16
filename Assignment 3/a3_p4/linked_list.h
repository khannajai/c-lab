/*
JTSK-320112
a3_p2.c
Jai Khanna
j.khanna@jacobs-university.de
*/

#ifndef LINKED_LIST 
#define LINKED_LIST

typedef struct list List;

struct list
{
    char info;
    List *next;
};

void print_list(List * my_list );

List * push_front ( List * my_list , char value );

List *pull_front(List *my_list);

List * push_back ( List * my_list , char value );

List *insert (List *my_list, char value, int pos);

List *reverse(List *my_list);

void dispose_list ( List * my_list );

#endif 