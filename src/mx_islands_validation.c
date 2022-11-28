#include "pathfinder.h"

static void count_islands(t_finder *path) {
    int counter = 1;

    path->unique_island = (char**)malloc(sizeof(char*) * path->num_of_words);
    path->unique_island[0] = mx_strdup(path->islands[1]);
    
    for (int i = 1; i < path->num_of_words; i++) {
        if (mx_isdigit(path->islands[i][0]))
            continue;
            
        for (int j = 0; j < counter; j++) {
            if (!mx_strcmp(path->unique_island[j], path->islands[i]))
                break;
            if (j == counter - 1)
                path->unique_island[counter++] = mx_strdup(path->islands[i]);
        }
    }
    
    if (counter != path->num_of_islands)
        mx_print_islands_error(path);
}

static void duplicate_islands(t_finder *path) {
    int line = 2;
    
    for (int i = 1; i < path->num_of_words; i +=3) {
        if (!mx_strcmp(path->islands[i + 1], path->islands[i]))
            mx_print_line_error(line);
        
        line++;
    }
}

static void duplicate_bridges(t_finder *path) {
    for (int i = 1; i < path->num_of_words; i += 3)
        for (int j = i + 3; j < path->num_of_words; j += 3)
            if (!mx_strcmp(path->islands[i], path->islands[j]) 
                || !mx_strcmp(path->islands[i], path->islands[j + 1]))
                if (!mx_strcmp(path->islands[i + 1], path->islands[j + 1]) 
                    || !mx_strcmp(path->islands[i + 1], path->islands[j])) {
                    mx_printerr("error: duplicate bridges\n");
                    exit(1);
                }
}

static void sum_of_bridges_lengths(t_finder *path) {
    long sum = 0;

    for (int i = 1; i < path->num_of_words; i++) {
        if (mx_isdigit(path->islands[i][0]))
            sum += mx_atoi(path->islands[i]);
            
        if (sum > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
    }
}

void mx_islands_validation(t_finder *path) {
    char *buff = mx_strdup(path->string);

    path->num_of_islands = mx_atoi(buff);
    if (path->num_of_islands < 2)
        mx_print_islands_error(path);
        
    for (int i = 0; buff[i] != '\0'; i++)
        buff[i] == ',' || buff[i] == '\n' ? (buff[i] = '-') : buff[i];
        
    path->num_of_words = mx_count_words(buff,'-');
    path->islands = mx_strsplit(buff,'-');
    count_islands(path);
    duplicate_islands(path);
    duplicate_bridges(path);
    sum_of_bridges_lengths(path);
    
    free(buff);
    free(path->string);
}

