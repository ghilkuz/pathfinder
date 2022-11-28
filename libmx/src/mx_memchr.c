#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *res_ptr = (unsigned char*)s;
    
    for (size_t i = 0; i < n; i++) {
        if (*res_ptr == (unsigned char)c) {
			return res_ptr;
	    }
	    
		res_ptr++;
    }
	
	return NULL;
}

