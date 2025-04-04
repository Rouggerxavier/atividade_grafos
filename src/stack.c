#include <stdlib.h>
#include "../include/stack.h"

Stack *create_stack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, int data) {
    StackNode *new_node = malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack *s) {
    if (is_empty_stack(s)) return -1;
    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

int is_empty_stack(Stack *s) {
    return s->top == NULL;
}

void free_stack(Stack *s) {
    while (!is_empty_stack(s)) pop(s);
    free(s);
}