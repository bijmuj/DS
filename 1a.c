#include <stdio.h>

void main()
{
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 0, eo[10], i;
    for (i = 0; i < 10; i++)
        if (list[i] % 2 == 0)
            eo[count++] = list[i];
    for (i = 0; i < 10; i++)
        if (list[i] % 2 != 0)
            eo[count++] = list[i];
    for (i = 0; i < 10; i++)
        printf("%d ", eo[i]);
}