#include <stdio.h>
#include "../include/queue.h"

int main() {
    Queue *q = create_queue();
    printf("Fila criada. Vazia? %d\n", is_empty(q));

    enqueue(q, 10);
    enqueue(q, 20);
    printf("Desenfileirando: %d\n", dequeue(q));
    printf("Desenfileirando: %d\n", dequeue(q));
    printf("Fila vazia agora? %d\n", is_empty(q));

    free_queue(q);
    return 0;
}