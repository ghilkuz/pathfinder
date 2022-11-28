#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;
    
    int num_of_words = 0;
    char **arr = (char**)malloc((mx_count_words(s, c) + 1) * sizeof(char*));

    while (*s) {
        if (*s != c) {
            int length_of_word = 0;
            
	        while (s[length_of_word] != c && s[length_of_word])
                length_of_word++;   
            
            arr[num_of_words] = mx_strndup(s, length_of_word);
            s += length_of_word;
            num_of_words++;
            continue;
        }
        s++;
    }
    
    arr[num_of_words] = NULL;
    return arr;
}

