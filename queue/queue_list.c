//
// Created by Lucien on 2019/12/22.
//

#include "queue_list.h"

void init(queue_ptr Q,element it){
    list_ptr temp = malloc(sizeof(struct list));
    temp->it = it;
    temp->next =NULL;
    Q->front = Q->rear = temp;
    Q->length = 1;

}

void clear(queue_ptr Q){           // front is list 's head , if not , dequeue will be difficult
    while (Q->front!=Q->rear){
        list_ptr temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
        Q->length--;
    }
    free(Q->front);
    Q->length--;

}

bool enqueue(queue_ptr Q,element it){
    list_ptr temp = malloc(sizeof(struct list));
    temp->it = it;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    Q->length++;
    return True;
}
bool dequeue(queue_ptr Q,element* it){
    if(Q->front!= NULL) {
        *it = Q->front->it;
        list_ptr temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
        Q->length--;
        return True;
    } else{
        printf("Fail to dequeue\n");
        return False;
    }

}

bool frontvalue(queue_ptr Q, element* it){
    *it = Q->front->it;
    return True;
}

int length(queue_ptr Q){
    return Q->length;
}