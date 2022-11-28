#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == 0) {
	    return malloc(size);
	}
	
    size_t curr_size = malloc_size(ptr);
        
    if (size <= curr_size) {
	    return ptr;
	}
	
    void *new_ptr = malloc(size);
    
    mx_memcpy(new_ptr, ptr, curr_size);
    free(ptr);
    return new_ptr;
}

