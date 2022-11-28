#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }
    
    int res = 0;
       
    if (mx_strlen(str) >= mx_strlen(sub)) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (!mx_strncmp(str + i, sub, mx_strlen(sub))) {
                res++;
            }
        }
    }
    return res;
}

