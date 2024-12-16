#include "random_char.h"

int my_random(int nb)
{
    return rand() % nb;
}

int my_strlen(char *nbr)
{
    int i = 0;

    while (nbr[i] != '\0') {
        i++;
    }
    return i;
}

int my_getnbr(char *nbr)
{
    int nb = 0;
    int i = 0;
    int flag = 0;

    if (nbr[0] == '-') {
        i = 1;
        flag = 1;
    }

    while (nbr[i] != '\0') {
        if (nb > INT_MAX / 10 || (nb == INT_MAX / 10 && (nbr[i] - '0') > INT_MAX % 10)) {
            return (flag == 1) ? INT_MIN : INT_MAX;
        }
        nb = nb * 10 + (nbr[i] - '0');
        i++;
    }
    if (flag == 1)
        return -nb;
    return nb;
}
