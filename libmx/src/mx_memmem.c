#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len) {
    if (big_len <= 0 || little_len <= 0 || big_len < little_len) {
        return NULL;
    }
    
    unsigned char *res = (unsigned char*)big;
    unsigned char *buff = (unsigned char*)little;

    while (*res) {
		if (mx_memcmp(res, buff, little_len - 1) == 0) {
			return res;
		}
		
	    res++;
	}
	
	return NULL;
}

