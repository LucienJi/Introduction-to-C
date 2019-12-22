//
// Created by Lucien on 2019/12/15.
//

#include "stack_linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#define elementtype int

struct list;
typedef struct list *list_ptr;
typedef list_ptr  Stack;

struct list{
    elementtype element;
    list_ptr next;
};

int isEmpty(Stack s){
    return s->next == NULL;
}
void pop(Stack s){
    list_ptr temp;
    if(isEmpty(s)){
        printf("Eorror");
    } else{
        temp = s->next;
        s->next = s->next->next;
        free(temp);
    }
}
void push(elementtype element,Stack s){
    list_ptr temp = malloc(sizeof(struct list));
    temp->element = element;
    temp->next = s->next;
    s->next = temp;
}
elementtype top(Stack s){
    if(isEmpty(s)){
        return 0;
        printf("Error");
    } else{
        return s->next->element;
    }
}
void makeEmpty(Stack s){
    if(s==NULL){
        printf("Empty");
    } else{
        while (!isEmpty(s)){
            pop(s);
        }
    }
}
Stack createStack(void){
    Stack s;
    s = malloc(sizeof(struct list));
    s->next = NULL;
    return s;
}

