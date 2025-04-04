#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

Stack *create_stack();
void push(Stack *s, int data);
int pop(Stack *s);
int is_empty_stack(Stack *s);
void free_stack(Stack *s);

#endif