#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue_list.h"

int main(){
    queue_ptr Queue = malloc(sizeof(struct queue));
    init(Queue,1);
    enqueue(Queue,2);
    enqueue(Queue,3);
    enqueue(Queue,4);

    
}