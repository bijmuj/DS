#include <stdio.h>
#include <malloc.h>

struct node
{
    int val;
    struct node *next;
};

//circularization
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
//same as enqueue operation
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

//recursize delete rear
//same as dequeue operation
struct node *delete (struct node *head)
{
    if (head)
    {
        struct node *temp = head;
        do
        {
            temp = temp->next;
        } while (temp->next->next != head);
        printf("bun at temp %d removed\n", temp->next->val);
        if (temp->next != temp)
        {
            if (temp->next)
            {
                temp->next->next = NULL;
                temp->next->val = 0;
                free(temp->next);
            }
            //pointing the next of the last value back to the first value
            temp->next = head;
        }
        else
        {
            temp->next = NULL;
            temp->val = 0;
            free(temp);
            return NULL;
        }
        return head;
    }
    else
    {
        printf("no buns to remove\n");
        return NULL;
    }
}

//display code
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

//decreases the temperature of  all buns in the queue
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
            //old buns cooled everytime a new bun is added
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