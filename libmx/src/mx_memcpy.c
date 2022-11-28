#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *res_dst = (unsigned char*)dst;
    
    for (size_t i = 0; i < n; i++) {
        res_dst[i] = ((unsigned char*)src)[i];
    }
    
    return res_dst;
}

