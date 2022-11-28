#include "pathfinder.h"

static void invalid_argc_or_file(int argc, char *argv[], t_finder *path) {
    int fd;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    
    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        free(path);
        exit(1);
    }
    
    close(fd);
}

static void empty_file_error(char *argv[], t_finder *path) {
    int fd;
    char *buff = mx_strnew(1);

    fd = open(argv[1], O_RDONLY);
    
    if (read(fd, buff, 1) < 1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        free(path);
        exit(1);
        close(fd);
    }
    
    mx_strdel(&buff);
    path->string = mx_file_to_str(argv[1]);
}

static void first_line_validation(t_finder *path) {
    while (*path->string != '\n') {
        if (!mx_isdigit(*path->string))
            mx_print_line_error(1);
        
        path->string++;
    }
        
    path->string++;
}

void mx_error_handling(int argc, char *argv[], t_finder *path) {
    char *buff;

    invalid_argc_or_file(argc, argv, path);
    empty_file_error(argv, path);
    buff = path->string;
    first_line_validation(path);
    mx_lines_validation(path);
    path->string = buff;
    mx_islands_validation(path);
}

