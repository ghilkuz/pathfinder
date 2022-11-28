#include "../inc/libmx.h"

static void bubble_sort_swaps(void **s1, void **s2) {
    void *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst != NULL && cmp != NULL) {
        for (t_list *i = lst; i; i = i->next) {
            for (t_list *j = lst; j->next; j = j->next) {
                if (cmp(j->data, j->next->data)) {
                    bubble_sort_swaps(&j->data, &j->next->data);
                }
            }
        }
    }

    return lst;
}

