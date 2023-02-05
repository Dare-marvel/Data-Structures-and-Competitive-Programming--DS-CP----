#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*prev;
    int data;
    struct node*next;
};

struct node*DeleteAtEnd(struct node*head){
    struct node*p=head;

    if(head==NULL){
        printf("Can't delete because list is empty\n");
        return NULL;
    }
    
    else if(head->next==NULL){
        free(head);
        printf("Deleted only item in list the list is empty now\n");
        return NULL;
    }
    
    else{
        while(p->next!=NULL){
            p=p->next;
        }
    struct node*q=p;
    p=p->prev;
    if(p!=NULL)
        p->next=NULL;
    free(q);
    return head;
    }
}

struct node*DeleteAtFront(struct node*head){
    if(head==NULL){
        printf("Can't delete because the list is empty\n");
        return NULL;
    }
    else if(head->next==NULL && head->prev==NULL){
        free(head);
        printf("List is empty now\n");
        return NULL;
    }
    else{
    struct node*p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
    }
}

struct node*InsertAtEnd(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    if(head==NULL){
        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
        return head;
    }
    else{
        struct node*p=head;
        
        while(p->next!=NULL){
        p=p->next;
        }
        
    ptr->prev=p;
    p->next=ptr;
    ptr->next=NULL;
    return head;
    }
    
}

struct node*InsertAtFront(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL){

        ptr->prev=NULL;
        ptr->next=NULL;
        head=ptr;
        return head;
    }
    else{
    
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
    return head;
    }
}

struct node*InsertBeforePosition(struct node*head,int checkData,int insData){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    
    ptr->data=insData;
    if(head==NULL){
        printf("List is empty,So can't insert anything\n");
        return NULL;
    }
    while(p->data!=checkData && p->next!=NULL){
        p=p->next;
    }
    
    struct node*q=p->prev;
    if(p->next==NULL && p->data!=checkData){
        printf("No such element exists!\n");
        return head;
    }
    else if(p->prev==NULL){
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        return head;
    }
    else{
        ptr->prev=p->prev;
        q->next=ptr;
        ptr->next=p;
        p->prev=ptr;
        return head;
    }

}

void Display(struct node*head){
    struct node*temp=head;
    if(head==NULL)
        printf("List is empty!\n");

    else{
    printf("Traversal of entire Linked List\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }
    }
}

struct node*DeleteAtPosition(struct node*head,int checkData){
    struct node*p=head;
    if(head==NULL){
        printf("No such element exists!\n");
        return NULL;
    }
    while(p->data!=checkData && p->next!=NULL){
        p=p->next;
    }
    if((p->next==NULL && p->data!=checkData)){
        printf("No such element exists!\n");
        return head;
    }
    else if(p->next==NULL && p->prev==NULL){
        free(p);
        printf("List is empty now\n");
        return NULL;
    }
    else if(p->next==NULL){
        head=DeleteAtEnd(head);
        return head;
    }
    else if(p->prev==NULL){
        head=DeleteAtFront(head);
        return head;
    }
    else if(p!=NULL){
        struct node*r=p->prev;
        r->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return head;
    }
    
}




int main(){
    struct node*head=NULL;
    int flag=0;
    do {
    int ch;

    printf("\nEnter your choice:\n");
    printf("1)Insert At Front\n2)Insert At End\n3)Insert with a given value\n");
    printf("4)Delete At Front\n5)Delete At End\n6)Delete with a given element\n7)Exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        {
            int ele;
            printf("Enter the element you want to insert:\n");
            scanf("%d",&ele);
            head=InsertAtFront(head,ele);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 2:
        {
            int ele;
            printf("Enter the element you want to insert:\n");
            scanf("%d",&ele);
            head=InsertAtEnd(head,ele);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 3:
        {
            int ele,check;
            printf("Enter the element you want to insert:\n");
            scanf("%d",&ele);
            printf("Enter the element before which you want to insert:\n");
            scanf("%d",&check);
            head=InsertBeforePosition(head,check,ele);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 4:
        {
            head=DeleteAtFront(head);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 5:
        {
            head=DeleteAtEnd(head);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 6:
        {
            int check;
            printf("Enter the element which you want to delete:\n");
            scanf("%d",&check);
            head=DeleteAtPosition(head,check);
            printf("Current Status:\n");
            Display(head);
            break;
        }
        case 7:
        {
            flag=1;
            printf("Program finished\n");
            break;
        }
        default:
        {
            printf("Invalid choice!\n");
            break;
        }
    }
    }while(flag!=1);
    
    return 0;
}