#include "../inc/libmx.h"

long mx_atol(const char *str) {
    long num = 0;
    int sign = (str[0] != '-') ? 1 : -1;
    const char *new;
 
    while (mx_isspace(*str))
            str++;       
    if (!mx_isdigit(str[0]) && str[0] != '+' && str[0] != '-') return 0;
    if (str[0] == '+' || str[0] == '-') str++;
    
    new = str;
    
    while (mx_isdigit(*new)) {
        num *= 10;
        num += *new - '0';
        new++;
    }
    if (*new != '\0') return 0;
    
    return sign * num;
}

