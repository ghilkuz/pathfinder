#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct s_finder {
    int num_of_islands;
    int num_of_words;
    char *string;
    char **islands;
    char **unique_island;
    int **result_arr;
    int **initial_arr;
}              t_finder;

typedef struct s_output {
    int distance;
    int *route;
}              t_output;

int main(int argc, char *argv[]);
void mx_error_handling(int argc, char *argv[], t_finder *path);
void mx_print_line_error(int line);
void mx_lines_validation(t_finder *path);
void mx_print_islands_error();
void mx_islands_validation(t_finder *path);
void mx_matrix(t_finder *path);
void mx_floyd_warshall_algorithm(t_finder *path);
void mx_print_result(t_finder *path);
void mx_clean_memory(t_finder *path);

#endif
