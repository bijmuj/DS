#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

//insert front
struct node *insert(int a, struct node *old_head)
{
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    if (new_head)
    {
        if (old_head)
            old_head->prev = new_head;
        new_head->val = a;
        new_head->next = old_head;
        new_head->prev = NULL;
        return new_head;
    }
    printf("AllocError: null returned\n");
    return NULL;
}

//connecting the two lists
//would've been much more efficient if I'd used to pointers for each list
void connect(struct node *head, struct node *tail)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = tail;
    tail->prev = head;
    temp = head;

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void main()
{
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct node *head = NULL, *tail = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (list[i] % 2 == 0)
            head = insert(list[i], head);
        else
            tail = insert(list[i], tail);
    }
    connect(head, tail);
}