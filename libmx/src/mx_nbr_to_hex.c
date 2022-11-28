#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int length = 0;
    unsigned long n = nbr;

    while (nbr != 0) {
        nbr /= 16;
        length++;
    }
    
    if (length == 0) return 0;
        
    char *hex_str = mx_strnew(length);

    for (int i = length - 1; i >= 0; i--) {
        int temp = n % 16;
        if (temp < 10) hex_str[i] = temp + 48;
        else hex_str[i] = temp + 32 + 55;
        n /= 16;
    }
    return hex_str;
}

