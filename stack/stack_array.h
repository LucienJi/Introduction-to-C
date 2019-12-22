//
// Created by Lucien on 2019/12/15.
//

#ifndef STACK_STACK_ARRAY_H
#define STACK_STACK_ARRAY_H
#define elementtype int
struct StackRecord;
typedef struct StackRecord* Stack;

int IsEmpty(Stack s);
int IsFull(Stack s);
Stack creatStack(void);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(elementtype element,Stack s);
void Pop(Stack s);
elementtype Top(Stack s);
#endif //STACK_STACK_ARRAY_H
