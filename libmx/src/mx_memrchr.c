#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *res_ptr = (unsigned char*)s + mx_strlen(s);
    
    for (size_t i = n; i > 0; i--) {
        if (*res_ptr == (unsigned char)c) {
			return res_ptr;
	    }
	    
		res_ptr--;
    }
	
	return NULL;
}
