#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define node struct node
//each node contains 4 digits of the numbers
node
{
    int val;
    node *next;
    node *prev;
};

//recursive insert rear operation
node *insert_rear(int v, node *head, node *prev)
{
    if (head)
    {
        head->next = insert_rear(v, head->next, head);
        return head;
    }
    else
    {
        head = (node *)malloc(sizeof(node));
        head->val = v;
        head->next = NULL;
        head->prev = prev;
        return head;
    }
}

//takes the 12 character string and breaks into 4 digit integer and inserts them into a list
node *insert(char a[], node *head)
{
    int j = 0;
    char v[4];
    for (int i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            v[j] = a[i * 4 + j];
        }
        head = insert_rear(atoi(v), head, NULL);
    }
    return head;
}

//deletes the last element of a list
int delete_rear(node *head)
{
    if (head)
    {
        int ret = 0;
        node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        ret = temp->val;
        if (temp->prev)
            temp->prev = temp->prev->next = NULL;
        free(temp);

        return ret;
    }
    printf("empty list\n");
    return 0;
}

//display code
void display(node *head)
{
    if (head)
    {
        printf("%d ", head->val);
        display(head->next);
    }
}

//insert front operation
node *insert_front(int v, node *old_head)
{
    node *new_head = (node *)malloc(sizeof(node));
    if (new_head)
    {
        new_head->val = v;
        new_head->next = old_head;
        new_head->prev = NULL;
        if (old_head)
            old_head->prev = new_head;
        return new_head;
    }
    return NULL;
}

//function to evaluate an expression (operand, operand, operator)
node *evaluate(node *op1, node *op2, char op)
{
    int cb = 0, v1, v2, res;
    node *result = NULL;
    for (int i = 0; i < 3; i++)
    {
        v1 = delete_rear(op1);
        v2 = delete_rear(op2);
        switch (op)
        {
        case '+':
            res = v1 + v2 + cb;
            break;
        case '-':
            res = v1 - v2 - cb;
            break;
        default:
            break;
        }
        cb = 0;
        if (res > 9999)
        {
            cb = 1;
            res -= 10000;
        }
        else if (res < 0)
        {
            cb = 1;
            res += 10000;
        }
        result = insert_front(res, result);
    }
    return result;
}

void main()
{
    int i;
    char in[12];
    node *A = NULL, *B = NULL, *C = NULL;

    printf("Enter value of A(12 digits):");
    scanf("%ld", &in);
    A = insert(in, A);

    printf("Enter value of B(12 digits):");
    scanf("%ld", &in);
    B = insert(in, B);

    printf("Enter value of C(12 digits):");
    scanf("%s", &in);
    C = insert(in, C);

    B = evaluate(B, C, '+');
    A = evaluate(A, B, '-');
    display(A);
}