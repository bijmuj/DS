#include <stdio.h>

void main()
{
    //giving a static list
    //can be replaced with a userdefined list
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = 0, eo[10], i;

    //looking for even numbers in the given list and putting them into second list
    for (i = 0; i < 10; i++)
        if (list[i] % 2 == 0)
            eo[count++] = list[i];

    //putting odd numbers from the first list into the second
    for (i = 0; i < 10; i++)
        if (list[i] % 2 != 0)
            eo[count++] = list[i];

    //displaying the second list
    for (i = 0; i < 10; i++)
        printf("%d ", eo[i]);
}