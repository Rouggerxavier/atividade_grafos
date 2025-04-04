#include <stdio.h>
#include <stdlib.h>
#include "../include/reader_list.h"
#include "../include/graph_list.h"

GraphList *read_graph_list(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int num_vertices;
    fscanf(file, "%d", &num_vertices);
    GraphList *g = graph_list_create(num_vertices);

    int u, v;
    while (fscanf(file, "%d %d", &u, &v) == 2) {
        graph_list_add_edge(g, u, v);
    }

    fclose(file);
    return g;
}