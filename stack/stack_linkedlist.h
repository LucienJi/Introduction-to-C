//
// Created by Lucien on 2019/12/15.
//

#ifndef STACK_STACK_LINKEDLIST_H
#define STACK_STACK_LINKEDLIST_H
#define elementtype int

struct list;
typedef struct list *list_ptr;
typedef list_ptr  Stack;
struct list;
int isEmpty(Stack s);
void pop(Stack s);
void push(elementtype element,Stack s);
elementtype top(Stack s);
void makeEmpty(Stack s);
Stack createStack(void);
#endif //STACK_STACK_LINKEDLIST_H
