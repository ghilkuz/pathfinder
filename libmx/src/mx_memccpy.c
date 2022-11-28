#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, 
                 int c, size_t n) {
    unsigned char *new_dst = (unsigned char*)dst;
    const unsigned char *new_src = (const unsigned char*)src;
    
    for (size_t i = 0; i < n; i++) {
		if (new_src[i] == (unsigned char)c) {
			new_dst[i] = new_src[i];
			return (void*)&(new_dst[i + 1]);
		} 
		else {
			new_dst[i] = new_src[i];
		}
	}
	
	return NULL;   
}

