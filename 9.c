#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tree struct t

tree
{
    char val;
    tree *left;
    tree *right;
};

int priority(char a)
{
    switch (a)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

//turns inf string into a tree
tree *make_tree(char inf[])
{
    int i, j = 0, l = 10, li, len = strlen(inf);
    char c;
    tree *node;
    node = (tree *)malloc(sizeof(tree));
    if (len == 1)
    {
        node->val = inf[0];
        node->left = node->right = NULL;
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            c = inf[i];
            if (priority(c) < l)
            {
                li = i;
                l = priority(c);
            }
        }
        node->val = inf[li];

        //probably could've done this better
        char rst[10], lst[10];
        for (i = 0; i < li; i++)
            lst[i] = inf[i];
        //just to be sure
        lst[i + 1] = '\0';

        for (i = li + 1; i < len; i++)
            rst[j++] = inf[i];
        rst[j + 1] = '\0';

        node->left = make_tree(lst);
        node->right = make_tree(rst);
    }
    return node;
}

tree *evaluate(tree *root)
{
    char op = root->val;
    int f = 0;
    int op1, op2, ans;
    if (root->left)
    {
        root->left = evaluate(root->left);
        f++;
    }
    if (root->right)
    {
        root->right = evaluate(root->right);
        f++;
    }
    if (f == 2)
    {
        if (priority(root->left->val) == 0 && priority(root->right->val) == 0)
        {
            switch (op)
            {
            case '+':
                op1 = atoi(root->left->val);
                op2 = atoi(root->right->val);
                ans = op1 + op2;
                root->val = ans + '0';
                break;
            case '-':
                op1 = atoi(root->left->val);
                op2 = atoi(root->right->val);
                ans = op1 - op2;
                root->val = ans + '0';
                break;
            default:
                break;
            }
            root->left->val = root->right->val = 0;
            free(root->left);
            free(root->right);
            root->left = root->right = NULL;
        }
    }
    return root;
}

void main()
{
    char inf[] = {"2+3-4"};
    tree *root;
    root = make_tree(inf);
    root = evaluate(root);
    printf("%c", root->val);
}