#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int res = 0;
    int i = 0;
    
    if (str[0] != '\0' && str[0] != c) {
        res++;
        i++;
    }
    
    for (; str[i] != '\0'; i++) {
        if (str[i] == c) {
            while (str[i] != '\0' && str[i] == c)
                i++;
            
            if (str[i] != c && str[i] != '\0')
                res++;
        }
    }
    
    return res;
}

