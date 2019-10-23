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
            //required check as old_head->prev crashes if old_head=NULL
            old_head->prev = new_head;
        new_head->val = a;
        new_head->next = old_head;
        new_head->prev = NULL;
        return new_head;
    }
    printf("AllocError: null returned\n");
    return NULL;
}

//connecting the two lists and displaying
void connect(struct node *head, struct node *head2)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;
    head2->prev = head;
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
    struct node *head = NULL, *head2 = NULL;
    for (int i = 9; i >= 0; i--)
    {
        //if the number is even inserting into first list
        if (list[i] % 2 == 0)
            head = insert(list[i], head);
        //else inserting into second list
        else
            head2 = insert(list[i], head2);
    }
    //joining the two lists
    connect(head, head2);
}