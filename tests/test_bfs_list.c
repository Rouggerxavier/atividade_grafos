#include <stdio.h>
#include <stdlib.h>
#include "../include/graph_list.h"
#include "reader_list.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <arquivo> <início> <fim>\n", argv[0]);
        return 1;
    }
    GraphList *g = read_graph_list(argv[1]);
    if (!g) return 1;
    bfs_list_print_path(g, atoi(argv[2]), atoi(argv[3]));
    graph_list_free(g);
    return 0;
}