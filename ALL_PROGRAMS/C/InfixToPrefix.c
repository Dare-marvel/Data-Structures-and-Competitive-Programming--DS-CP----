#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// stack to convert infix to prefix
struct stack{
    int size;
    int top;
    char * arr;
};

//Linked list to take the string as input
struct sll{
    char data;
    struct sll * next;
};

//Node for expression tree
struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
    struct tree *next;
};

struct tree *head = NULL;

// Functions of stack
int isFull(struct stack * s){
    if(s->top==s->size-1){
        return 1;
    }
    return -1;
}

int isEmpty(struct stack * s){
    if(s->top==-1){
        return 1;
    }
    return -1;
}

void push(char data,struct stack * s){
    if(isFull(s)==1){
        printf("Stack is Overflowing\n");
        return ;
    }
    s->top++;
    s->arr[s->top]=data;
    printf("Pushed element:%c\n",data);
}

void pop(struct stack * s){
    if(isEmpty(s)==1){
        printf("Stack is underflowing\n");
        return ;
    }
    printf("Popped element:%c\n",s->arr[s->top]);
    s->top--;
}

char peek(struct stack * s){
    return s->arr[s->top];
}

//Function to get the precedence of operators while converting from infix to prefix
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    return -1;
}

//Function to swap ) with ( and vice-versa
int Bracket_swap(struct sll*head,int n){
    int k=n;
    struct sll * ptr=head;
    while(ptr!=NULL){
        if(ptr->data==')'){
            k--;
            ptr->data='(';
            ptr=ptr->next;
        }
        else if(ptr->data=='('){
            k--;
            ptr->data=')';
            ptr=ptr->next;
        }
        else{
            ptr=ptr->next;
        }
    }
    return k;
}

// Function to insert at end in linked list
struct sll*InsertAtEnd(struct sll * head,char data){
    struct sll*ptr=(struct sll*)malloc(sizeof(struct sll));
   
    ptr->data=data;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        return head;
    }

    else{
        struct sll*p=head;
        while(p->next!=NULL){
            p=p->next;
        }
    
        p->next=ptr;
        return head;
    }
}

//Function to insert at first
struct sll*InsertAtFirst(struct sll*head,char data){
    struct sll*ptr=(struct sll*)malloc(sizeof(struct sll));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}

//Function to traverse a linked list
void LinkedListTraversal(struct sll*head){
    struct sll*ptr=head;
    printf("Traversal of entire linked list\n");
    while(ptr!=NULL){
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }

}

//Functions of stack to convert tree to expression tree

//Function for popping a node in a stack 
struct tree *tree_pop()
{
    struct tree *ptr = head;
    head = head->next;
    return ptr;
}

//Function for pushing a node in a stack 
void tree_push(struct tree *top)
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

//Function to create node 
struct tree *creation(char data)
{
    struct tree *new = (struct tree *)malloc(sizeof(struct tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->next = NULL;
    return new;
}

//Function for inorder traversal
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
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=50;
    s->arr=(char *)malloc(s->size * sizeof(char));
    int n;

    struct sll * head1=NULL;
    int i;
    
    
    printf("Enter the length of the string:\n");
    scanf("%d",&n);
    
    char inf[n];
    
    printf("Enter the infix expression:\n");
    scanf("%s",inf);

    for(i=n-1;i>=0;i--){
        head1=InsertAtEnd(head1,inf[i]);
    }

    int k=Bracket_swap(head1,n);

    head1=InsertAtFirst(head1,'(');
    head1=InsertAtEnd(head1,')');

    LinkedListTraversal(head1);
    printf("\n");

    char final[n+2];

    struct sll * ptr = head1;
    
    i=0;

    while(ptr!=NULL){
        final[i]=ptr->data;
        ptr=ptr->next;
        i++;
    }

    //Now convert final string to postfix
    printf("Final string to be converted to prefix:%s\n",final);
    char prefix[k];

    int c=-1;

    for(i=0;i<n+2;i++){
        
        if(isalpha(final[i]) || isdigit(final[i])){
            ++c;
            prefix[c]=final[i];
        }

        else if(final[i]=='('){
            push(final[i],s);
        }

        else if(final[i]==')'){
            printf("Popped element:)\n");
            while(isEmpty(s)!=1 && peek(s)!='('){
                ++c;
                prefix[c]=peek(s);
                pop(s);
            }
            if(peek(s)!='(' && isEmpty(s)!=1){
                exit(1);
            }
            else{
                pop(s);
            }
        }

        else{
            while(isEmpty(s)!=1 && precedence(final[i])<=precedence(peek(s))){
                ++c;
                prefix[c]=peek(s);
                pop(s);
            }
            push(final[i],s);
        }
    }
    while(isEmpty(s)!=1){
        ++c;
        prefix[c]=peek(s);
        pop(s);
    }
    prefix[k]='\0';
    //Reverse the obtained prefix expression to get a prefix expression
    strrev(prefix);

    printf("\nResulatant prefix expression:%s\n",prefix);
    
    struct tree *right_ins;
    struct tree *left_ins;
    struct tree *top;

    int j;
    for (j = k - 1; j >= 0; j--)
    {
        if (prefix[j] == '+' || prefix[j] == '-' || prefix[j] == '*' || prefix[j] == '/' || prefix[j] == '^')
        {
            top = creation(prefix[j]);
            left_ins = tree_pop(head);
            right_ins = tree_pop(head);
            top->left = left_ins;
            top->right = right_ins;
            tree_push(top);
        }
        else
        {
            struct tree *ptr = creation(prefix[j]);
            tree_push(ptr);
        }
    }
    printf("Inorder Traversal of Tree:\n");
    Inorder(top);
    printf("\n");
return 0;
}