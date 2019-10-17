#include <stdio.h>
#include <malloc.h>
#include <string.h>

//each node contains 4 digits of the numbers
struct node
{
    char val1[4];
    struct node *next;
    struct node *prev;
};

struct node *insert(char a[], struct node *head)
{
    //inserting at rear
    if (!head)
    {
        head = (struct node *)malloc(sizeof(struct node));
        strcpy(head->val1, a);
        head->next = NULL;
        head->prev = NULL;
    }
    else if (head->next)
    {
        head->next = insert(a, head->next);
    }
    else
    {
        head->next = (struct node *)malloc(sizeof(struct node));
        strcpy(head->next->val1, a);
        head->next->next = NULL;
        head->next->prev = head;
    }
    return head;
}

void main()
{
    int i, c = 0;
    char c[12], v1[4];
    struct node *A = NULL, *B = NULL, *C = NULL;
    printf("Enter value of A(12 digits):");
    scanf("%s", c);
    for (i = 0; i < 3; i++)
    {
        for (i = 0; i < 12; i++)
    }
}