#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *create_queue();
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int is_empty(Queue *q);
void free_queue(Queue *q);

#endif