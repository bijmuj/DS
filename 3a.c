#include <stdio.h>

void sort(int t[])
{
    int i, j, temp;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6 - i; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
        printf("%c, %d\n", (char)t[i], t[i]);
}

void main()
{
    char word[6] = {'G', 'a', 'n', 'd', 'h', 'i'};
    int t[6];
    for (int i = 0; i < 6; i++)
    {
        t[i] = (int)word[i];
    }
    sort(t);
}