#include <stddef.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        i++;
        my_putchar('\n');
    }
    return (0);
}
