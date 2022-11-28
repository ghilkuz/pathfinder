#include "../inc/libmx.h"

static int check_space_for_word(char *trim, bool is_sep) {
    int word = 0;

    for (int i = 0; trim[i] != 0; i++)
        if (!mx_isspace(trim[i])) {
            is_sep = false;
            word++;
        }
        
    return word;
}

static int check_space_for_space(char *trim, bool is_sep) {
    int space = 0;

    for (int i = 0; trim[i] != 0; i++)
        if (mx_isspace(trim[i]) && !is_sep) {
            is_sep = true;
            space++;
        }
        
    return space;
}

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;
        
    char *trim = mx_strtrim(str);
    bool is_sep = false;
    char *new = mx_strnew(check_space_for_space(trim, is_sep) 
                          + check_space_for_word(trim, is_sep));
    int j = 0;
    
    for (int i = 0; i < mx_strlen(trim); i++)
        if (!mx_isspace(trim[i])) {
            new[j++] = trim[i];
            is_sep = false;
        }
        else if (mx_isspace(trim[i]) && !is_sep) {
            new[j++] = ' ';
            is_sep = true;
        }
    free(trim);
    return new;
}

