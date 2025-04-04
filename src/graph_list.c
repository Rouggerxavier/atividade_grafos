#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_list.h"
#include "../include/queue.h"
#include "../include/stack.h"  // Inclusão adicionada

GraphList *graph_list_create(int num_vertices) {
    GraphList *g = malloc(sizeof(GraphList));
    g->num_vertices = num_vertices;
    g->lists = malloc(num_vertices * sizeof(Node *));
    for (int i = 0; i < num_vertices; i++) {
        g->lists[i] = NULL;
    }
    return g;
}

void graph_list_add_edge(GraphList *g, int u, int v) {
    Node *new_node = malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = g->lists[u];
    g->lists[u] = new_node;

    new_node = malloc(sizeof(Node));
    new_node->vertex = u;
    new_node->next = g->lists[v];
    g->lists[v] = new_node;
}

void graph_list_free(GraphList *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        Node *current = g->lists[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(g->lists);
    free(g);
}

void bfs_list_print_path(GraphList *g, int start, int end) {
    int *parent = malloc(g->num_vertices * sizeof(int));
    for (int i = 0; i < g->num_vertices; i++) parent[i] = -1;

    Queue *q = create_queue();
    enqueue(q, start);
    parent[start] = -1;
    int found = 0;

    while (!is_empty(q)) {
        int u = dequeue(q);
        if (u == end) {
            found = 1;
            break;
        }
        Node *current = g->lists[u];
        while (current) {
            int v = current->vertex;
            if (parent[v] == -1) {
                parent[v] = u;
                enqueue(q, v);
            }
            current = current->next;
        }
    }

    if (!found) {
        printf("Não há caminho entre %d e %d\n", start, end);
    } else {
        int *path = malloc(g->num_vertices * sizeof(int));
        if (!path) {
            fprintf(stderr, "Erro de alocação\n");
            exit(EXIT_FAILURE);
        }
        int current = end;
        int count = 0;
        while (current != -1) {
            path[count++] = current;
            current = parent[current];
        }
        printf("Caminho: ");
        for (int i = count - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i > 0) printf(" -> ");
        }
        printf("\n");
        free(path);
    }

    free(parent);
    free_queue(q);
}

void dfs_list_iterative(GraphList *g, int start_vertex) {
    int *visited = calloc(g->num_vertices, sizeof(int));
    Stack *s = create_stack();
    push(s, start_vertex);

    while (!is_empty_stack(s)) {
        int u = pop(s);
        if (!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);
            Node *current = g->lists[u];
            Stack *temp = create_stack();
            while (current) {
                if (!visited[current->vertex]) {
                    push(temp, current->vertex);
                }
                current = current->next;
            }
            while (!is_empty_stack(temp)) {
                push(s, pop(temp));
            }
            free_stack(temp);
        }
    }

    free(visited);
    free_stack(s);
    printf("\n");
}