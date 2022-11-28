#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    *count = 0;
    int low = 0;
    int high = size - 1;

    if (!*arr) return -1;
    
    while (low <= high) {
        int middle = (low + high) / 2;
    
        (*count)++;
        if (mx_strcmp(arr[middle], s) < 0)
            low = middle + 1;
        else if (mx_strcmp(arr[middle], s) == 0)
            return middle;
        else
            high = middle - 1;
    }
    *count = 0;
    return -1;
}

