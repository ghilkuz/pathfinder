#include "pathfinder.h"

static void del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path->num_of_islands; i++)
            free(arr[i]);
         
        free(arr);
    }
}

void mx_clean_memory(t_finder *path) {
    mx_del_strarr(&path->unique_island);
    del_int_arr(path->result_arr, path);
    del_int_arr(path->initial_arr, path);
    free(path);
}

