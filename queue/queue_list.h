//
// Created by Lucien on 2019/12/22.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef UNTITLED_QUEUE_LIST_H
#define UNTITLED_QUEUE_LIST_H
#define element int
#define bool int
#define True 1
#define False 0
typedef struct list* list_ptr;
typedef struct queue* queue_ptr;
struct list{
    element it;
    list_ptr next;

};

struct queue{
    int length;
    list_ptr front;
    list_ptr rear;
};

void init(queue_ptr,element);
void clear(queue_ptr);
bool enqueue(queue_ptr,element);
bool dequeue(queue_ptr,element*);
bool frontvalue(queue_ptr,element*);
int length(queue_ptr);



#endif //UNTITLED_QUEUE_LIST_H
