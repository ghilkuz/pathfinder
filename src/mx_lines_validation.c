#include "pathfinder.h"

static void check_line(t_finder *path, int line) {
    if (*path->string == '-' && !mx_isalpha(*(path->string - 1)) 
        && !mx_isalpha(*(path->string + 1)))
        mx_print_line_error(line);
        
    path->string++;
    
    while (*path->string != ',') {
        if (!mx_isalpha(*path->string))
            mx_print_line_error(line);
        
        path->string++;
    }
            
    if (*path->string == ',' && !mx_isalpha(*(path->string - 1)) 
        && !mx_isdigit(*(path->string + 1)))
        mx_print_line_error(line);
        
    path->string++;
}

void mx_lines_validation(t_finder *path) {
    for (int line = 2; *path->string != '\0'; path->string++) {
        while (*path->string != '-') {
            if (!mx_isalpha(*path->string))
                mx_print_line_error(line);
                
            path->string++;
        }
                
        check_line(path, line);
        
        while (*path->string != '\n') {
            if (!mx_isdigit(*path->string) || mx_atol(path->string) > INT_MAX)
                mx_print_line_error(line);
                
            line++;
            path->string++;
        }
    }
}

