#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

typedef struct {
    int num_vertices;
    int **matrix;
} GraphMatrix;

GraphMatrix *graph_matrix_create(int num_vertices);
void graph_matrix_add_edge(GraphMatrix *g, int u, int v);
void graph_matrix_free(GraphMatrix *g);
void bfs_matrix_print_path(GraphMatrix *g, int start, int end);
void dfs_matrix_iterative(GraphMatrix *g, int start_vertex);

#endif