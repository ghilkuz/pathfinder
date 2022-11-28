#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0) return -2;

    (*lineptr) = (char*)mx_realloc(*lineptr, buf_size);
    mx_memset((*lineptr), '\0', malloc_size((*lineptr)));
    size_t num_of_bytes = 0;
    char buff;

    if (read(fd, &buff, 1)) {
        if (buff == delim) return num_of_bytes;
        
        (*lineptr) = (char*)mx_realloc(*lineptr, num_of_bytes + 1);
        (*lineptr)[num_of_bytes] = buff;
        num_of_bytes++;
    }
    else return -1;

    while (read(fd, &buff, 1)) {
        if (buff == delim) break;
        
        if (num_of_bytes >= buf_size)
            (*lineptr) = (char*)mx_realloc(*lineptr, num_of_bytes + 1);

        (*lineptr)[num_of_bytes] = buff;
        num_of_bytes++;
    }
    (*lineptr) = (char*)mx_realloc(*lineptr, num_of_bytes + 1);

    size_t free_num_of_bytes = malloc_size((*lineptr)) - num_of_bytes;
    
    mx_memset(&(*lineptr)[num_of_bytes], '\0', free_num_of_bytes);
    return num_of_bytes + 1;
}

