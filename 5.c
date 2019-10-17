#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
};

//recursively circularising again
struct node *circ(struct node *old_head, struct node *new_head)
{
    if (old_head->next == new_head->next)
    {
        old_head->next = new_head;
        return old_head;
    }
    return circ(old_head->next, new_head);
}

//insert front
struct node *insert(int a, struct node *old_head)
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

//delete front
struct node *delete (struct node *old_head)
{
    if (old_head)
    {
        struct node *temp = old_head;
        while (temp->next != old_head)
        {
            temp = temp->next;
        }
        temp->next = old_head->next;
        printf("Bun at temp %d removed\n", old_head->val);
        old_head->next = NULL;
        old_head->val = 0;
        free(old_head);
        return temp->next;
    }
    printf("no buns to remove\n");
    return NULL;
}

void display(struct node *head)
{
    if (head)
    {
        struct node *temp = head;
        do
        {
            printf("%d ", temp->val);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
    else
    {
        printf("no buns\n");
    }
}

struct node *cool(struct node *head)
{
    if (head)
    {
        struct node *temp = head;
        do
        {
            temp->val -= 5;
            temp = temp->next;
        } while (temp != head);
        return head;
    }
    return NULL;
}

void main()
{
    struct node *head = NULL;
    int c, run = 1;
    printf("1. add bun \n2. remove bun \n3. display bun temps \n4. exit\n");

    while (run)
    {
        scanf("%d", &c);
        switch (c)
        {
        default:
            printf("invalid\n");
            break;
        case 1:
            head = cool(head);
            head = insert(80, head);
            printf("bun added\n");
            break;
        case 2:
            head = delete (head);
            break;
        case 3:
            printf("buns are at temp:\n");
            display(head);
            break;
        case 4:
            run = 0;
            break;
        }
    }
}