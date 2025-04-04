CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g -std=c99
BIN_DIR = bin
SRC_DIR = src
TEST_DIR = tests

all: dirs test_bfs_matrix test_bfs_list test_dfs_matrix test_dfs_list

dirs:
	mkdir -p $(BIN_DIR)

test_bfs_matrix: $(TEST_DIR)/test_bfs_matrix.c $(SRC_DIR)/graph_matrix.c $(SRC_DIR)/reader_matrix.c $(SRC_DIR)/queue.c $(SRC_DIR)/stack.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^

test_bfs_list: $(TEST_DIR)/test_bfs_list.c $(SRC_DIR)/graph_list.c $(SRC_DIR)/reader_list.c $(SRC_DIR)/queue.c $(SRC_DIR)/stack.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^

test_dfs_matrix: $(TEST_DIR)/test_dfs_matrix.c $(SRC_DIR)/graph_matrix.c $(SRC_DIR)/reader_matrix.c $(SRC_DIR)/stack.c $(SRC_DIR)/queue.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^

test_dfs_list: $(TEST_DIR)/test_dfs_list.c $(SRC_DIR)/graph_list.c $(SRC_DIR)/reader_list.c $(SRC_DIR)/stack.c $(SRC_DIR)/queue.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^

clean:
	rm -rf $(BIN_DIR)