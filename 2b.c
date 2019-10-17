#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

//insert front again
struct node *insert(int a, struct node *old_head)
{
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    if (new_head)
    {
        new_head->val = a;
        new_head->next = old_head;
        new_head->prev = NULL;
        if (old_head)
            old_head->prev = new_head;
        return new_head;
    }
    printf("AllocError: null returned\n");
    return NULL;
}

void display(struct node *head)
{
    struct node *temp = head;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void main()
{
    int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct node *head = NULL;
    for (int i = 8; i >= 0; i -= 2)
        head = insert(list[i], head);
    for (int i = 9; i >= 0; i -= 2)
        head = insert(list[i], head);
    display(head);
}