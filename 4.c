#include <stdio.h>
#include <malloc.h>

struct node
{
    char val;
    struct node *next;
};

//insert front operation
struct node *insert(char a, struct node *old_head)
{
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    if (new_head)
    {
        new_head->val = a;
        new_head->next = old_head;
        return new_head;
    }
    printf("AllocError: null returned\n");
    return NULL;
}

//display code
void display(struct node *head)
{
    struct node *temp = head;
    //repeating the whole list twice to show that the list is circular
    for (int i = 0; i < 20; i++)
    {
        printf("%c ", temp->val);
        temp = temp->next;
    }
}

//circularising the list
struct node *circ(struct node *head)
{
    struct node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

struct node *rearrange(struct node *head)
{
    struct node *caps, *smalls;
    struct node *temp, *temp2, *new_head;
    caps = smalls = head;
    //finding the first capital
    while ((int)caps->val >= 96 && caps)
    {
        caps = caps->next;
    }
    //rearranging the list
    new_head = smalls;
    do
    {
        temp = caps->next;
        caps->next = smalls->next;
        smalls->next = caps;
        smalls = caps->next;
        temp2 = smalls;
        while (temp2->next != caps)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        caps = temp;
    } while (caps != new_head && smalls != new_head);
    return new_head;
}

void main()
{
    char c, list[10] = {"EDCBAedcba"};
    struct node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        head = insert(list[i], head);
    }
    head = circ(head);

    head = rearrange(head);
    display(head);
}