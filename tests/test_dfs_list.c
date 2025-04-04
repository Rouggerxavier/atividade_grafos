#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_list.h"
#include "reader_list.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <arquivo> <início>\n", argv[0]);
        return 1;
    }
    GraphList *g = read_graph_list(argv[1]);
    if (!g) return 1;
    dfs_list_iterative(g, atoi(argv[2]));
    printf("\n");
    graph_list_free(g);
    return 0;
}