#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, 
                        const char *replace) {
	if (str == NULL || sub == NULL || replace == NULL) return NULL;
	
	int len = mx_strlen(str) 
	          - (mx_count_substr(str, sub) * mx_strlen(sub)) 
	          + (mx_count_substr(str, sub) * mx_strlen(replace));
    char *res = mx_strnew(len);
    int i = 0;
    
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&res[i], replace);
            i += mx_strlen(replace);
            str += mx_strlen(sub);
        }
        else res[i++] = *str++;
    }
    res[i] = '\0';
    return res;
}

