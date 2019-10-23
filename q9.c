#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define node struct node

node
{
    char val[5];
    node *right;
    node *left;
};

int precedence(char a)
{
    //priority = / > * > + > -
    switch (a)
    {
    // case '^':
    //     return 5;
    case '/':
        return 4;
    case '*':
        return 3;
    case '+':
        return 2;
    case '-':
        return 1;
    default:
        return 0;
    }
}

//only supporting these operators="+-*/"
//no parentheses
node *make_tree(node *root, char inf[])
{
    root = (node *)malloc(sizeof(node));
    int i, j, len = strlen(inf), nops = 0, least = 4, least_index = 0, prd;
    //first we search for operators
    //if none are found then the whole string is pushed to node
    //else if multiple operators exist then we find the operator with least precedence
    for (i = 0; i < len; i++)
    {
        prd = precedence(inf[i]);
        if (prd != 0)
        {
            if (prd < least)
            {
                least = prd;
                least_index = i;
            }
            nops++;
        }
    }

    if (nops == 0)
    {
        strcpy(root->val, inf);
        root->left = root->right = NULL;
    }
    else
    {
        char left[20], right[20];
        for (i = 0; i < least_index; i++)
        {
            left[i] = inf[i];
        }
        left[i] = '\0'; //for safetly

        root->val[0] = inf[i++];
        root->val[1] = '\0'; //for safety

        for (j = 0; i < len; j++, i++)
        {
            right[j] = inf[i];
        }
        right[j] = '\0'; //for safety

        root->left = make_tree(root->left, left);
        root->right = make_tree(root->right, right);
    }
    return root;
}

//displays tree
//code from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", root->val);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void main()
{
    char inf[10] = {"2+3-4"};
    node *root = make_tree(root, inf);
    print2D(root);
}