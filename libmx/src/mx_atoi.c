#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int num = 0;
    int i = 0;
    int sign = 1;
 
    while (mx_isspace(str[i]))
        i++;
 
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
 
    for (; str[i] && mx_isdigit(str[i]); i++)
        num = num * 10 + (str[i] - '0');
        
    return sign * num;
}
