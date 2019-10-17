#include <stdio.h>
#include <stdlib.h>

#define tree struct t

tree
{
    char aob;
    tree *left;
    tree *right;
};

char tr[10] = {"bbaababaa"};
int d = 0;
//initializes the above tree
tree *init(tree *root)
{
    root = NULL;
    if (d < 10)
    {
        root = (tree *)malloc(sizeof(tree));
        root->aob = tr[d++];
        if (root->aob != 'a')
        {
            root->left = init(root->left);
            root->right = init(root->right);
        }
        else
        {
            root->left = root->right = NULL;
        }
    }
    return root;
}

//returns no of apples present past a node
int no_apples(tree *root)
{
    int c = 0;
    if (root->aob == 'a')
        c++;
    else
    {
        if (root->left)
            c += no_apples(root->left);
        if (root->right)
            c += no_apples(root->right);
    }
    return c;
}

//return depth remaining past a node
int depth(tree *root)
{
    int l, r, c;
    l = r = c = 0;
    if (root)
    {
        c++;
        if (root->left)
            l = depth(root->left);
        if (root->right)
            r = depth(root->right);
    }
    if (l == r)
        c += l;
    else if (l > r)
        c += l;
    else
        c += r;
    return c;
}

//removes an apple from the tree
tree *rm(tree *root)
{
    tree *node = root;
    int dl, dr;
    if (no_apples(root) > 0)
    {
        //searching for a node that has apples past it and is one up from deepest
        while (depth(node) > 2)
        {
            dl = depth(node->left);
            dr = depth(node->right);
            if (dl >= dr)
            {
                if (no_apples(node->left) > 0)
                    node = node->left;
                else
                    node = node->right;
            }
            else
            {
                if (no_apples(node->right) > 0)
                    node = node->right;
                else
                    node = node->left;
            }
        }
        //removing the apple containing node
        if (node->left)
        {
            if (node->left->aob == 'a')
            {
                free(node->left);
                node->left = NULL;
            }
        }
        else
        {
            free(node->right);
            node->right = NULL;
        }
        printf("an apple was removed\n");
    }
    else
        printf("no apples left");
    return root;
}

//displays tree
//code from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
//was feeling too lazy to write something but I really needed to check
void print2DUtil(tree *root, int space)
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
    printf("%c\n", root->aob);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(tree *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void main()
{
    tree *root = (tree *)malloc(sizeof(tree));
    root = init(root);
    int c, i, r = 1;
    printf("1. display tree\n2. remove apple\n3. quit\n");
    while (r)
    {
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            print2D(root);
            break;
        case 2:
            printf("no of apples to remove= ");
            scanf("%d", &i);
            for (int j = 0; j < i; j++)
                root = rm(root);
            break;
        case 3:
            r = 0;
            break;
        default:
            printf("invalid\n");
            break;
        }
    }
}