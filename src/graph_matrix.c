#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_matrix.h"
#include "../include/queue.h"
#include "../include/stack.h"

GraphMatrix *graph_matrix_create(int num_vertices) {
    printf("[DEBUG] Criando grafo com matriz de adjacência (%d vértices)\n", num_vertices);
    GraphMatrix *g = malloc(sizeof(GraphMatrix));
    if (!g) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o grafo.\n");
        return NULL;
    }
    g->num_vertices = num_vertices;
    g->matrix = malloc(num_vertices * sizeof(int *));
    if (!g->matrix) {
        fprintf(stderr, "Erro: Falha ao alocar memória para a matriz.\n");
        free(g);
        return NULL;
    }
    for (int i = 0; i < num_vertices; i++) {
        g->matrix[i] = calloc(num_vertices, sizeof(int));
        if (!g->matrix[i]) {
            fprintf(stderr, "Erro: Falha ao alocar memória para a linha %d.\n", i);
            for (int j = 0; j < i; j++) free(g->matrix[j]);
            free(g->matrix);
            free(g);
            return NULL;
        }
    }
    return g;
}

void graph_matrix_add_edge(GraphMatrix *g, int u, int v) {
    printf("[DEBUG] Adicionando aresta: %d <-> %d\n", u, v);
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

void graph_matrix_free(GraphMatrix *g) {
    printf("[DEBUG] Liberando grafo de matriz\n");
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

void bfs_matrix_print_path(GraphMatrix *g, int start, int end) {
    printf("[DEBUG] Iniciando BFS (Matriz): %d -> %d\n", start, end);
    fflush(stdout);

    int *parent = malloc(g->num_vertices * sizeof(int));
    if (!parent) {
        fprintf(stderr, "Erro: Falha ao alocar memória para 'parent'.\n");
        return;
    }
    for (int i = 0; i < g->num_vertices; i++) parent[i] = -1;

    Queue *q = create_queue();
    if (!q) {
        fprintf(stderr, "Erro: Falha ao criar a fila.\n");
        free(parent);
        return;
    }
    printf("[DEBUG] Fila criada\n");
    fflush(stdout);

    enqueue(q, start);
    parent[start] = -1;
    int found = 0;

    printf("[DEBUG] Iniciando busca...\n");
    fflush(stdout);

    while (!is_empty(q)) {
        int u = dequeue(q);
        printf("[DEBUG] Desenfileirando vértice: %d\n", u);
        fflush(stdout);

        if (u == end) {
            found = 1;
            printf("[DEBUG] Vértice destino %d encontrado!\n", end);
            fflush(stdout);
            break;
        }

        printf("[DEBUG] Explorando vizinhos de %d\n", u);
        fflush(stdout);
        for (int v = 0; v < g->num_vertices; v++) {
            if (g->matrix[u][v] && parent[v] == -1) {
                parent[v] = u;
                enqueue(q, v);
                printf("[DEBUG] Enfileirando vértice: %d (pai: %d)\n", v, u);
                fflush(stdout);
            }
        }
    }

    if (!found) {
        printf("Não há caminho entre %d e %d\n", start, end);
    } else {
        printf("[DEBUG] Construindo caminho...\n");
        fflush(stdout);
        int *path = malloc(g->num_vertices * sizeof(int));
        if (!path) {
            fprintf(stderr, "Erro: Falha ao alocar memória para o caminho.\n");
        } else {
            int current = end;
            int count = 0;
            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }
            printf("Caminho de %d para %d: ", start, end);
            for (int i = count - 1; i >= 0; i--) {
                printf("%d", path[i]);
                if (i > 0) printf(" -> ");
            }
            printf("\n");
            free(path);
        }
    }

    free(parent);
    free_queue(q);
    printf("[DEBUG] BFS concluído\n");
    fflush(stdout);
}

void dfs_matrix_iterative(GraphMatrix *g, int start_vertex) {
    printf("[DEBUG] Iniciando DFS iterativo (Matriz) a partir de %d\n", start_vertex);
    fflush(stdout);

    int *visited = calloc(g->num_vertices, sizeof(int));
    if (!visited) {
        fprintf(stderr, "Erro: Falha ao alocar memória para 'visited'.\n");
        return;
    }

    Stack *s = create_stack();
    if (!s) {
        fprintf(stderr, "Erro: Falha ao criar a pilha.\n");
        free(visited);
        return;
    }
    printf("[DEBUG] Pilha criada\n");
    fflush(stdout);

    push(s, start_vertex);
    printf("[DEBUG] Empilhando vértice inicial: %d\n", start_vertex);
    fflush(stdout);

    while (!is_empty_stack(s)) {
        int u = pop(s);
        printf("[DEBUG] Desempilhando vértice: %d\n", u);
        fflush(stdout);

        if (!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);
            fflush(stdout);

            for (int v = g->num_vertices - 1; v >= 0; v--) {
                if (g->matrix[u][v] && !visited[v]) {
                    push(s, v);
                    printf("[DEBUG] Empilhando vértice: %d\n", v);
                    fflush(stdout);
                }
            }
        }
    }

    free(visited);
    free_stack(s);
    printf("\n[DEBUG] DFS concluído\n");
    fflush(stdout);
}