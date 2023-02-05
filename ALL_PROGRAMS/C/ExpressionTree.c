#include <stdio.h>
#include <stdlib.h>

struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
    struct tree *next;
};



struct tree *head = NULL;


struct tree *pop()
{
    struct tree *ptr = head;
    head = head->next;
    return ptr;
}

void push(struct tree *top)
{
    if (head == NULL)
    {
        head = top;
    }
    else
    {
        top->next = head;
        head = top;
    }
}

struct tree *creation(char data)
{
    struct tree *new = (struct tree *)malloc(sizeof(struct tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->next = NULL;
    return new;
}

void Inorder(struct tree *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%c", root->data);
        Inorder(root->right);
    }
}


int main()
{
    int n;
    char c;
    struct tree *right_ins;
    struct tree *left_ins;
    struct tree *top;
    
    printf("Enter the length of the string:\n");
    scanf("%d", &n);
    

    char pre[n];
    // printf("Enter the prefix equation:\n");
    // scanf("%s", pre);
    // for(int i=0;i<n;i++){
    //     scanf(" %c",&pre[i]);
    // }
    int j;
    for (j = n - 1; j >= 0; j--)
    {
        if (pre[j] == '+' || pre[j] == '-' || pre[j] == '*' || pre[j] == '/' || pre[j] == '^')
        {
            top = creation(pre[j]);
            left_ins = pop(head);
            right_ins = pop(head);
            top->left = left_ins;
            top->right = right_ins;
            push(top);
        }
        else
        {
            struct tree *ptr = creation(pre[j]);
            push(ptr);
        }
    }
    printf("Inorder Traversal of Tree:\n");
    Inorder(top);
    printf("\n");
    return 0;
}