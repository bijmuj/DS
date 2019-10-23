#include <stdio.h>

void sort(int t[])
{
    int i, j, temp;
    //using bubble sort on t
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
    //display code
    for (int i = 0; i < 6; i++)
        printf("%c, %d\n", (char)t[i], t[i]);
}

void main()
{
    char word[6] = {"Gandhi"};
    int t[6];
    //inserting the ascii values of word into t
    for (int i = 0; i < 6; i++)
    {
        t[i] = (int)word[i];
    }
    //sorting t
    sort(t);
}