#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_matrix.h"
#include "reader_matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo> <início>\n", argv[0]);
        return 1;
    }
    GraphMatrix *g = read_graph_matrix(argv[1]);
    if (!g) return 1;
    dfs_matrix_iterative(g, atoi(argv[2]));
    printf("\n");
    graph_matrix_free(g);
    return 0;
}