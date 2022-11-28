#include "../inc/libmx.h"

static int check_spaces_start(const char *str) {
    int start = 0;
    
    while (start < mx_strlen(str)) {
        if (!mx_isspace(str[start]))
            break;
        start++;
    }
    return start;
}

static int check_spaces_end(const char *str) {
    int end = 0;
    
    for (int i = mx_strlen(str) - 1; i > 0; i--) {
        if (!mx_isspace(str[i]))
            break;
        end++;
    }
    return end;
}

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;
    
    char *src = mx_strnew(mx_strlen(str));
    
    src = mx_strncpy(src, str, mx_strlen(str));
    
    int start = check_spaces_start(str);
    int end = check_spaces_end(str);
    char *new = mx_strnew(mx_strlen(str) - start - end);
    int j = 0;
    
    for (int i = start; i < mx_strlen(str) - end; i++) {
        new[j] = src[i];
        j++;
    }
    
    mx_strdel(&src);
    return new;
}

