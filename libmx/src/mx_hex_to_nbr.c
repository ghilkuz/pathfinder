#include "../inc/libmx.h"

static unsigned long convertation(const char *hex, int len) {
    unsigned long num = 0;
    unsigned long base = 1;
    
    for (int i = 0; i <= len; i++) {
        if (mx_isdigit(hex[len - i])) {
            num += (hex[len - i] - 48) * base;
            base *= 16;
        }
        else if (mx_isupper(hex[len - i])) {
            num += (hex[len - i] - 55) * base;
            base *= 16;
        }
        else if (mx_islower(hex[len - i])) {
            num += (hex[len - i] - 87) * base;
            base *= 16;
        }
    }
    
    return num;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;

    if (hex != NULL)
        while (hex[len])
            len++;
    else
        return 0;
    
    unsigned long num = convertation(hex, len);
    
    return num;
}

