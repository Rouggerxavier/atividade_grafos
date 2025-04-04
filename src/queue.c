#include <stdlib.h>
#include "../include/queue.h"

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data) {
    QueueNode *new_node = malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear) {
        q->rear->next = new_node;
        q->rear = new_node;
    } else {
        q->front = q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) return -1;
    QueueNode *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return data;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

void free_queue(Queue *q) {
    while (!is_empty(q)) dequeue(q);
    free(q);
}