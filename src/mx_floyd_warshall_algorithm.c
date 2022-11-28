#include "pathfinder.h"

void mx_floyd_warshall_algorithm(t_finder *path) {
    for (int i = 0; i < path->num_of_islands; i++)
        for (int j = 0; j < path->num_of_islands; j++)
            path->initial_arr[i][j] = path->result_arr[i][j];
    
    
    for (int k = 0; k < path->num_of_islands; k++)
        for (int i = 0; i < path->num_of_islands; i++)
            for (int j = 0; j < path->num_of_islands; j++) {
                int sum = path->result_arr[i][k] + path->result_arr[k][j];
                
                if (path->result_arr[i][k] != INT_MAX 
                    && path->result_arr[k][j] != INT_MAX 
                    && sum < path->result_arr[i][j])
                    path->result_arr[i][j] = sum;
            }
}

