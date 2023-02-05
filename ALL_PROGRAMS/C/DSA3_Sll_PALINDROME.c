#include<stdio.h>
#include<stdlib.h>
struct node{
char data;
struct node*next;
};

struct node*InsertAtFirst(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}

struct node*InsertAtEnd(struct node*head,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
   
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        return head;
    }
    else{
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    
    p->next=ptr;
    return head;
    }
}

void DeleteAtEnd(struct node*head){
    
    if(head==NULL)
        printf("List is empty!\n");
    
    else{
        struct node*p=head;
        struct node*q=head->next;
        while(q->next!=NULL){
            q=q->next;
            p=p->next;
        }
        p->next=NULL;
        free(q);
    }
}
void LinkedListTraversal(struct node*head){
    struct node*ptr=head;
    printf("Traversal of entire linked list\n");
    while(ptr!=NULL){
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }

}

void Pallindrome_check(struct node*q,struct node*head,int mid){
    int flag=0;
    printf("\nFinal Answer:\n");
    struct node*q1=head;
    for(int i=0;i<mid;i++){
        
        if(q1->data!=q->data){
            printf("Breaking point\n");
            printf("First part:%c , Second part=%c\n",q1->data,q->data);
            printf("The string is not a Pallindrome\n");
            flag=1;
            return;
        }
        else{
            q1=q1->next;
            q=q->next;
        }
    }
    if(flag==0){
        printf("The string is a Pallindrome\n");
        return;
    }
}

struct node*InsertReverted(struct node*head,int mid,int n,struct node*p2){
    struct node*temp=p2;
        for(int i=mid;i<n;i++){
            head=InsertAtFirst(head,temp->data);
            temp=temp->next;
        }
        
    return head;
}

struct node*MidPointer(struct node*head,int mid,int n){
    struct node*q=head;

    for(int k=0;k<mid;k++)
        q=q->next;      //q has reached the mid
    
    if(n%2!=0){
        q=q->next;
    }
    return q;
}

void Delete_mid_last(struct node*head,int mid){ 
    
    for(int i=0;i<mid;i++){
        DeleteAtEnd(head);
    }
}
int main(){
    int n,i;
    printf("Enter the length of the string:\n");
    scanf("%d",&n);
    struct node*head=NULL;
    char arr[n];
    
    printf("Enter a string\n");
    scanf("%s",arr);
    
    //Inserting elements into the linked list
    for(i=0;i<n;i++)
       head=InsertAtEnd(head,arr[i]);
    
    //view of linked list after inserting elements
    LinkedListTraversal(head);
    printf("\n");
    int mid=n/2;
    
    int ind=0;
    struct node*p1=head;
  
        while(ind!=mid-1){
            p1=p1->next; 
            ind++;
        }
    
    //Pointer to add the last half of the list to first
    struct node*p2=p1->next;
    
    //Inserting elements from mid to last at the beginning in reverse order
    head=InsertReverted(head,mid,n,p2);
    
    //Deleting the elements from mid to last which are not required
    Delete_mid_last(head,mid);

    //For breaking the list into half
    p1->next=NULL;
    
    //Bringing a pointer to the middlemost element
    struct node*q=MidPointer(head,mid,n);

    
    printf("\n");
    printf("After entering the last half first:\n");
    LinkedListTraversal(head);
    printf("\n");
    Pallindrome_check(q,head,mid);
return 0;    
}