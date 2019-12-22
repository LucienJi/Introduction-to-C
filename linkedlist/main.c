#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
int main(){
    llist_ptr LLink = malloc(sizeof(struct Linkedlist));
    init_Linkedlist(LLink);
    append(LLink,1);
    append(LLink,1);
    append(LLink,1);
    append(LLink,1);
    append(LLink,1);
    append(LLink,1);
    set_pos(LLink,3);
    printlist(LLink);
    return 0;
}
