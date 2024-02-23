#include "my.h"
#include "navy.h"

int is_line_shared(char *str1, char *str2)
{
    char temp = str1[2];

    while (temp != str1[5] + 1) {
        if (temp == str2[2] || temp == str2[5])
            return (1);
        temp++;
    }
    return (0);
}

int is_col_shared(char *str1, char *str2)
{
    char temp = str1[3];

    while (temp != str1[6] + 1) {
        if (temp == str2[3] || temp == str2[6])
            return (1);
        temp++;
    }
    return (0);
}

int are_lines_crossing(char **tab)
{
    int i = 0;
    int j = 1;

    while (i != 4) {
        while (j != 4) {
            if (is_col_shared(tab[i], tab[j]) == 1 && \
                is_line_shared(tab[i], tab[j]) == 1)
                    return (1);
            j++;
        }
        i++;
        j = i + 1;
    }
    return (0);
}