#include <stdio.h>
#include <malloc.h>

struct node
{
    char val;
    struct node *next;
};

//circularising the list recursively
struct node *circ(struct node *old_head, struct node *new_head)
{
    if (old_head->next == new_head->next)
    {
        old_head->next = new_head;
        return old_head;
    }
    return circ(old_head->next, new_head);
}

//inserting front
struct node *insert(char a, struct node *old_head)
{
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    if (new_head)
    {
        new_head->val = a;
        if (old_head)
        {
            new_head->next = old_head;
            old_head = circ(old_head, new_head);
        }
        else
            new_head->next = new_head;
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
        printf("%c ", temp->val);
        temp = temp->next;
    }
}

void main()
{
    char c, list[10] = {"abcdeABCDE"};
    struct node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            c = list[i / 2];
        else
            c = list[(i / 2) + 5];
        head = insert(c, head);
    }
    display(head);
}