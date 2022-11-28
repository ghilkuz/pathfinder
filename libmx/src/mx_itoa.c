#include "../inc/libmx.h"

char *mx_itoa(int number) {
    number = (long long)number;
    char *str = NULL;

    if (number == 0) {
        str = mx_strnew(1);
        str[0] = '0';
        return str;
    }
    
    if (number == -2147483648) {
        str = mx_strnew(12);
        str = "-2147483648";
        return str;
        //return "-2147483648";
    }

    int length = 0;
    long long copy_number = number;

    if (copy_number < 0) {
        copy_number *= -1;
        length++;
    }
    
    for (; copy_number != 0; length++) copy_number /= 10;
    str = mx_strnew(length);
    
    if (number < 0) {
        str[0] = '-';
        number *= -1;
    }
    
    str[length--] = '\0';
    for (; (number != 0 && length >= 0) && str[length] != '-'; number /= 10) 
        str[length--] = (number % 10) + '0';
    return str;
}

