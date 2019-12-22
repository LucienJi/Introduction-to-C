//
// Created by Lucien on 2019/12/11.
//

#ifndef LINKEDLIST_LINKED_LIST_H
#define LINKEDLIST_LINKED_LIST_H
#define TRUE  1
#define False 0
typedef int BOOL;
typedef int element_type;
typedef struct list* list_ptr;
typedef struct Linkedlist* llist_ptr;

struct list{
    element_type element;
    list_ptr next;

};
struct Linkedlist{
    list_ptr head;
    list_ptr tail;
    list_ptr fence;
    int leftcnt;
    int rightcnt;
};
void init_Linkedlist(llist_ptr);
void removeall(llist_ptr);
void renewall(llist_ptr);
void set_start(llist_ptr);
void set_end(llist_ptr);
void next(llist_ptr);
void back(llist_ptr);

int left_length(llist_ptr );
int right_length(llist_ptr );
BOOL get_value(llist_ptr ,element_type* );
BOOL insert(llist_ptr ,element_type );
BOOL append(llist_ptr ,element_type );
BOOL delete(llist_ptr);
BOOL set_pos(llist_ptr ,int );

void printlist(llist_ptr);



#endif //LINKEDLIST_LINKED_LIST_H
