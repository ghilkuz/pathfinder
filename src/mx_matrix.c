#include "pathfinder.h"

static int get_num_of_islands(t_finder *path, char *island) {
    for (int i = 0; i < path->num_of_islands; i++)
        if (mx_strcmp(island, path->unique_island[i]) == 0)
            return i;
    
    return 0;
}

void mx_matrix(t_finder *path) {
    int i;
    int j;
    
    path->initial_arr = (int**)malloc(sizeof(int*) * path->num_of_islands);
    path->result_arr = (int**)malloc(sizeof(int*) * path->num_of_islands);
    for (i = 0; i < path->num_of_islands; i++) {
        path->initial_arr[i] = (int*)malloc(sizeof(int*) * path->num_of_islands);
        path->result_arr[i] = (int*)malloc(sizeof(int*) * path->num_of_islands);
        for (j = 0; j < path->num_of_islands; j++)
            path->result_arr[i][j] = i != j ? INT_MAX : 0;
    }
    
    for (int index = 1; index < path->num_of_words; index += 3) {
        i = get_num_of_islands(path, path->islands[index]);
        j = get_num_of_islands(path, path->islands[index + 1]);
        path->result_arr[i][j] = mx_atoi(path->islands[index + 2]);
        path->result_arr[j][i] = mx_atoi(path->islands[index + 2]);
    }
    mx_del_strarr(&path->islands);
}

