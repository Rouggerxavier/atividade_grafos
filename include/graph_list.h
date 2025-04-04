#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    int num_vertices;
    Node **lists;
} GraphList;

// Cria um grafo com lista de adjacência
GraphList *graph_list_create(int num_vertices);

// Adiciona uma aresta ao grafo (não direcionado)
void graph_list_add_edge(GraphList *g, int u, int v);

// Libera a memória do grafo
void graph_list_free(GraphList *g);

// Busca em largura (BFS) e imprime o caminho de 'start' a 'end'
void bfs_list_print_path(GraphList *g, int start, int end);

// Busca em profundidade iterativa (DFS com pilha)
void dfs_list_iterative(GraphList *g, int start_vertex);

#endif