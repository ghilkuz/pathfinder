#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    
    int num_of_swaps = 0;
    char *pivot = arr[(left + right) / 2];
    
    if (left < right) {
        int j = left;
        int k = right;
        
        pivot = arr[(j + k) / 2];
        
        while (j <= k) {
            while (mx_strlen(arr[j]) < mx_strlen(pivot)) j++;
            while (mx_strlen(arr[k]) > mx_strlen(pivot)) k--;
            
            if (j <= k) {
                if (mx_strlen(arr[j]) != mx_strlen(arr[k])) {
                    char *temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                    num_of_swaps++; 
                }
                k--;
                j++;
            }
        }
        num_of_swaps += mx_quicksort(arr, left, k);
        num_of_swaps += mx_quicksort(arr, j, right);
    } 
    return num_of_swaps;
}

