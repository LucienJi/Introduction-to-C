//
// Created by Lucien on 2019/12/15.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"
struct StackRecord{
    int capacity;
    int TopElement;
    elementtype* array;
};
Stack create(int maxcapacity){
    Stack s = malloc(sizeof(struct StackRecord));
    s->capacity = maxcapacity;
    s->TopElement = -1;
    s->array = malloc(sizeof(elementtype)*maxcapacity);
    return s;
}
int IsEmpty(Stack s){
    return s->TopElement == -1;
}
int IsFull(Stack s){
    return s->TopElement == s->capacity-1;
}

void DisposeStack(Stack s){
    if(s!=NULL){
        free(s->array);
        free(s);
    }
}

void MakeEmpty(Stack s){
    s->TopElement = -1;
}

void Push(elementtype element,Stack s){
    if(!IsFull(s)){
        s->array[s->TopElement+1] = element;
        s->TopElement++;
    }else{
        printf("Full");
    }
}
void Pop(Stack s){
    if(!IsEmpty(s)){
        s->TopElement--;
    } else{
        printf("Empty");
    }
}
elementtype Top(Stack s){
    if(!IsEmpty(s)){
        return s->array[s->TopElement];
    } else{
        printf("Eorror");
        return -1;
    }
}