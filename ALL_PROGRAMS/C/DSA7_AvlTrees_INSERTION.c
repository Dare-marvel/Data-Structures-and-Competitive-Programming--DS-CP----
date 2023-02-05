#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *new_node)
{
    if (new_node == NULL)
    {
        return 0;
    }
    return new_node->height;
}

struct node *create(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;

    return ptr;
}

int findMax(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else{
        return n2;
    }
}

int balanceFact(struct node *new)
{
    if (new == NULL)
    {
        return 0;
    }
    return height(new->left) - height(new->right);
}

struct node *leftRotation(struct node *root)
{
    struct node *rtright = root->right;
    struct node *rtrl = rtright->left;

    rtright->left = root;
    root->right = rtrl;

    root->height = 1 + findMax(height(root->left), height(root->right));
    rtright->height = 1 + findMax(height(rtright->left), height(rtright->right));

    return rtright;
}

struct node *rightRotation(struct node *root)
{
    struct node *rtleft = root->left;
    struct node *rtlr = rtleft->right;

    rtleft->right = root;
    root->left = rtlr;

    root->height = 1 + findMax(height(root->left), height(root->right));
    rtleft->height = 1 + findMax(height(rtleft->left), height(rtleft->right));

    return rtleft;
}

struct node *Insertion(struct node *root, int data)
{
    if (root == NULL)
    {
        return (create(data));
    }
    else if (root->data > data)
    {
        root->left = Insertion(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = Insertion(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + findMax(height(root->left), height(root->right));

    int bal = balanceFact(root);

    //LL Rotation
    if (bal > 1 && root->left->data > data)
    {
        return rightRotation(root);
    }

    //RR Rotation
    if (bal < -1 && root->right->data < data)
    {
        return leftRotation(root);
    }

    //RL Rotation
    if (bal > 1 && root->left->data < data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //LR Rotation
    if (bal < -1 && root->right->data > data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void Inorder(struct node *root)
{

    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d bf=%d, ", root->data,balanceFact(root));
        Inorder(root->right);
    }
}
int main()
{

    struct node *root = NULL;
    int val, ch;

    int flag = 0;
    do
    {
        printf("Enter your choice:\n1)Insertion\n2)Exit\n");
        scanf("%d",&ch);
        

        switch (ch)
        {
        case 1:
        {
            printf("Enter the value to be inserted:\n");
            scanf("%d",&val);
            root = Insertion(root, val);
            printf("Inorder Traversal:\n");
            Inorder(root);
            printf("\n");
            break;
        }
        case 2:
        {
            flag = 1;
            printf("Program finished!\n");
            break;
        }
        default:
        {
            printf("Invalid choice!\n");
            break;
        }

        }

    } while (flag != 1);

    return 0;
}