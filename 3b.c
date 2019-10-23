#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
};

//recursive insert rear operation
struct node *insert_rear(int a, struct node *head)
{
    if (head)
    {
        head->next = insert_rear(a, head->next);
        return head;
    }
    head = (struct node *)malloc(sizeof(struct node));
    if (head)
    {
        head->val = a;
        head->next = NULL;
    }
    return head;
}

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

//returns a sorted list
struct node *sort(struct node *head)
{
    struct node *temp = head, *head2 = NULL;
    while (temp)
    {
        head2 = insert_sorted(temp->val, head2);
        temp = temp->next;
    }
    return head2;
}

//recursive display code
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
    char word[6] = {"Gandhi"};
    struct node *head = NULL;
    //inserting "Gandhi" into the list
    for (int i = 0; i < 6; i++)
    {
        head = insert_rear((int)word[i], head);
    }
    head = sort(head);
    //displaying the list
    display(head);
}