#include <stdio.h>

void main()
{
    //static list
    int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int list2[10], eo = 0, i;

    //from index 1 taking every other element in the list and adding to second list
    for (i = 1; i < 10; i += 2)
        list2[eo++] = list[i];

    //same as above but for even indexed elements
    for (i = 0; i < 10; i += 2)
        list2[eo++] = list[i];

    //displaying
    for (i = 0; i < 10; i++)
        printf("%d ", list2[i]);
}