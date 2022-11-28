#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new_back = mx_create_node(data);
    t_list *temp = NULL;
    
    if (*list == NULL || list == NULL) {
        *list = new_back;
    }
    else {
        temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_back;
    }
}

