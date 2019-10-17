#include <stdio.h>

void main()
{
    int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int list2[10], eo = 0, i;
    for (i = 1; i < 10; i += 2)
        list2[eo++] = list[i];
    for (i = 0; i < 10; i += 2)
        list2[eo++] = list[i];
    for (i = 0; i < 10; i++)
        printf("%d ", list2[i]);
}