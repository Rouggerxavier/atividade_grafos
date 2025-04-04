#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_matrix.h"
#include "reader_matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <arquivo> <início> <fim>\n", argv[0]);
        return 1;
    }
    GraphMatrix *g = read_graph_matrix(argv[1]);
    if (!g) return 1;
    bfs_matrix_print_path(g, atoi(argv[2]), atoi(argv[3]));
    graph_matrix_free(g);
    return 0;
}