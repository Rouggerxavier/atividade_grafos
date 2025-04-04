#include <stdio.h>
#include <stdlib.h>
#include "../include/reader_matrix.h"
#include "../include/graph_matrix.h"

GraphMatrix *read_graph_matrix(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int num_vertices;
    fscanf(file, "%d", &num_vertices);
    GraphMatrix *g = graph_matrix_create(num_vertices);

    int u, v;
    while (fscanf(file, "%d %d", &u, &v) == 2) {
        graph_matrix_add_edge(g, u, v);
    }

    fclose(file);
    return g;
}