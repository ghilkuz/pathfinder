#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *new_front = mx_create_node(data);
    t_list *temp = NULL;
    
    if (*list == NULL || list == NULL) {
        *list = new_front;
    }
    else {
        temp = *list;
        *list = new_front;
        new_front->next = temp;
    }
}

