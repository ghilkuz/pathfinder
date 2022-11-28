#include "../inc/libmx.h"

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    else if (n < 0) {
        if (n == -2147483648) {
            write(1, "-2147483648", 11);
            return;
        }
        mx_printchar('-');
        n *= -1;
    }
    
    if (n >= 10)
        mx_printint(n / 10);
        
    char res = (n % 10) + 48;
    
    mx_printchar(res);
}

