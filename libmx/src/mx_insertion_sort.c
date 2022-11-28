#include "../inc/libmx.h"

int mx_insertion_sort(char **arr, int size) {
    char *key = 0;
    int j = 0;
    int num_of_shifts = 0;  
    
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && mx_strlen(arr[j]) > mx_strlen(key)) {
            num_of_shifts++;
            arr[j + 1] = arr[j];
            j--;
        }
            arr[j + 1] = key;
    }
    
    return num_of_shifts;
}

