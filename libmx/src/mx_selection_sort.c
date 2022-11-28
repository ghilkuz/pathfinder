#include "../inc/libmx.h"

int mx_selection_sort(char **arr, int size) {
    int pos = 0;
    int num_of_swaps = 0;
    
    for (int i = 0; i < size; i++) {
        pos = i;
        for (int j = i; j < size; j++)
            if (mx_strlen(arr[pos]) > mx_strlen(arr[j]) 
                || (mx_strlen(arr[pos]) == mx_strlen(arr[j])
                && mx_strcmp(arr[pos], arr[j]) > 0))
                pos = j;
                
        if (pos != i) {
            char *temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            num_of_swaps++;
        }
    }
    return num_of_swaps;
}

