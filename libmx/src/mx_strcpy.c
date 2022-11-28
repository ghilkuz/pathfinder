#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;

    for (int j = 0; src[j] != '\0'; j++) {
	    dst[j] = src[j];
	    i++;
    }

    dst[i] = '\0';
    return dst;
}

