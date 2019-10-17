#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
};

//recursively inserting characters into proper positions according to their ascii values
struct node *insert_sorted(int a, struct node *head)
{
    if (head && a > head->val)
    {
        head->next = insert_sorted(a, head->next);
        return head;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = a;
    temp->next = head;
    return temp;
}

void display(struct node *head)
{
    if (head)
    {
        printf("%c, %d\n", (char)head->val, head->val);
        display(head->next);
    }
    return;
}

void main()
{
    char word[6] = {'G', 'a', 'n', 'd', 'h', 'i'};
    struct node *head = NULL;
    for (int i = 0; i < 6; i++)
    {
        head = insert_sorted((int)word[i], head);
    }
    display(head);
}