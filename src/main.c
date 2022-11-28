#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_finder *path = (t_finder*)malloc(sizeof(t_finder));

    mx_error_handling(argc, argv, path);
    mx_matrix(path);
    mx_floyd_warshall_algorithm(path);
    mx_print_result(path);
    return 0;
}
