#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define False 0
#define size sizeof(struct Linkedlist)
//typedef int BOOL;
//typedef int element_type;
//typedef struct list* list_ptr;
//typedef struct Linkedlist* llist_ptr;

/*struct list{
    element_type element;
    list_ptr next;

};*/
/*struct Linkedlist{
    list_ptr head;
    list_ptr tail;
    list_ptr fence;
    int leftcnt;
    int rightcnt;
};*/

void init_Linkedlist(llist_ptr linkedlist){
    list_ptr head = malloc(sizeof(struct list));
    linkedlist->head = head;
    linkedlist->head->next = NULL;
    linkedlist->head->element = -1;
    linkedlist->tail = head;
    linkedlist->fence  =head;
    linkedlist->leftcnt=0;
    linkedlist->rightcnt = 0;

}

void removeall(llist_ptr listlink){
    while (listlink->head!=NULL){      // 用fence 可以代替temp
        listlink->fence = listlink->head;
        listlink->head = listlink->head->next;
        free(listlink->fence);   // 此时的listlink 是call by reference
    }
}
void renewall(llist_ptr listlink){
    removeall(listlink);
    init_Linkedlist(listlink);
}

void set_start(llist_ptr listlink){
    listlink->fence = listlink->head;
    listlink->rightcnt = listlink->rightcnt+listlink->leftcnt;
    listlink->leftcnt =0;
}
void set_end(llist_ptr listlink){
    listlink->fence = listlink->tail;
    listlink->leftcnt +=listlink->rightcnt;
    listlink->rightcnt = 0;
}
void next(llist_ptr listlink){
    if(listlink->fence!=listlink->tail){
        listlink->fence = listlink->fence->next;
        listlink->leftcnt++;
        listlink->rightcnt--;
    }
}
void back(llist_ptr listlink){
    while (listlink->fence!=listlink->head){
        list_ptr temp = listlink->head;
        while(temp->next!=listlink->fence){
            temp = temp->next;
        }
        listlink->fence = temp;            // 诺，call by reference
    }
}

int left_length(llist_ptr linklist){
    return linklist->leftcnt;
}
int right_length(llist_ptr linklist){
    return linklist->rightcnt;
}
BOOL get_value(llist_ptr linklist,element_type* it){
    if(linklist->fence->next==NULL){    //但这是定义 我对fence的定义，去fence右侧的值
        return False;
    } else{
        *it = linklist->fence->next->element;  //call by reference
        return TRUE;
    }
}
BOOL insert(llist_ptr linklist,element_type it){
    list_ptr temp = malloc(sizeof(struct list));
    temp->element = it;
    temp->next = linklist->fence->next;
    linklist->fence->next = temp;
    if(linklist->tail==linklist->fence){
        linklist->tail = linklist->fence->next;// 这是在尾部插item，需要改变尾部
    }
    linklist->rightcnt++;
    return TRUE;
}
BOOL append(llist_ptr linklist,element_type it){
    list_ptr temp = malloc(sizeof(struct list));
    temp->element = it;
    temp->next = NULL;
    linklist->tail->next = temp;
    linklist->tail = temp;
    linklist->rightcnt++;
    return TRUE;
}
BOOL delete(llist_ptr linklist){
    if(linklist->fence == linklist->tail){
        return False;
    }
    else{
        list_ptr temp = linklist->fence->next;
        linklist->fence->next = temp->next;
        if(linklist->fence->next == linklist->tail){
            linklist->tail = linklist->fence;
        }
        free(temp);
        linklist->rightcnt--;
        return TRUE;
    }
}
BOOL set_pos(llist_ptr linklist,int pos){
    if((pos<0)||(pos>linklist->rightcnt+linklist->leftcnt)){
        return False;
    } else{
        linklist->fence = linklist->head;
        for(int i = 0; i<pos ;i++){
            linklist->fence = linklist->fence->next;
        }
        linklist->rightcnt = linklist->rightcnt+linklist->leftcnt-pos;
        linklist->leftcnt = pos;
        return TRUE;
    }
}

void printlist(llist_ptr linklist){
    list_ptr temp = linklist->head;
    printf("[");
    temp = temp->next;
    while (temp!=NULL){
        printf("%d ",temp->element);
        if(temp == linklist->fence){
            printf("|");
        }
        temp = temp->next;
    }
    printf("]");
}

void sort(llist_ptr linklist, list_ptr array[]){
element_type temp;
list_ptr node_temp = linklist->head->next;
int len = linklist->leftcnt+linklist->rightcnt;
for(int i = 0;i<len-1;i++){

    while(node_temp!=NULL){

    }
}
}
