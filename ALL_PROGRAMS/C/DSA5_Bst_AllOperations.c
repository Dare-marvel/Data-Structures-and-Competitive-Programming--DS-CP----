#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*left;
    int data;
    struct node*right;
};

//Postorder is VLR
void Preorder(struct node*root){
//Call the function recursively until we have reached the end
    if(root!=NULL){
    printf("%d ",root->data);//Print data
    Preorder(root->left);//Recur the function to the left of the current node
    Preorder(root->right);//Recur the function to the right of the current node
    }
}

//Postorder is LRV
void Postorder(struct node*root){
//Call the function recursively until we have reached the end
    if(root!=NULL){
        Postorder(root->left);//Recur the function to the left of the current node
        Postorder(root->right);//Recur the function to the right of the current node
        printf("%d ",root->data);//Print data
    }
}

//Inorder is LVR
void Inorder(struct node*root){ 
    //Call the function recursively until we have reached the end
    if(root!=NULL){
    Inorder(root->left);//Recur the function to the left of the current node
    printf("%d ",root->data);//Print data
    Inorder(root->right);//Recur the function to the right of the current node
    }
}

struct node*Creation(int val){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

void Insertion(int value,struct node*root){
    //For storing the leaf node
    struct node*prev=NULL;
    //While loop is for searching for the node hence it goes while it's not equal to null
    while(root!=NULL){
        prev=root;
        //If value is already present get out of function
        if(value ==root->data){
            printf("The value you entered is already present in the tree.So can't insert!\n");
            return ;
        }
        //If value is less than root value go to the left
        else if(value<root->data){
            root=root->left;
        }
        //If value is greater than root value go to the right
        else{
            root=root->right;
        }
    }
    //After appropriate leaf node has been found create a new node
    struct node*new_node =Creation(value);

    //If value is less than value of leaf node insert to the left
    if(value<prev->data){
        prev->left=new_node;
    }

    //If value is greater than value of leaf node insert to the right
    else{
        prev->right=new_node;
    }

}

//Inorder successor is the element which succeeds the current element in Inorder Traversal
//Pass in the node to the right of the current node
int InorderSuccessor(struct node*root){
    struct node*temp=root;
    //Inorder successor is the leftmost node of the right subtree of the current node
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int Search(struct node*root,int value){
    while(root!=NULL){
        // If value is found stop
        if(value==root->data){
            return 1;
        }
        //If value is less than root value go to the left
        else if(value<root->data){
            root=root->left;
        }
        //If value is greater than root value go to the right
        else{
            root=root->right;
        }
    }
    return 0;
}
struct node*Deletion(struct node*root,int data){
   
    //If data is less than data of root node go to the left subtree
    if(data < root->data){
        root->left=Deletion(root->left,data);
    }

    //If data is greater than data of root node go to the right subtree
    else if(data > root->data){
        root->right=Deletion(root->right,data);
    }

    //Steps after reaching the node to be deleted
    else{
        
        //If the left subtree of the node to be deleted is NULL 
        //free the node and replace it by the node at the right of it
        if(root->left == NULL){
            struct node*ptr=root->right;
            free(root);
            return ptr;
        }

        //If the right subtree of the node to be deleted is NULL 
        //free the node and replace it by the node at the left of it
        else if(root->right == NULL){
            struct node*ptr=root->left;
            free(root);
            return ptr;
        }

        //If the node to the right and left are not null
        else{
            int temp=InorderSuccessor(root->right);//Store the value of the Inorder successor in a temporary variable
            root->data=temp;//Store the value of Inorder successor in root
            root->right=Deletion(root->right,temp);//Delete the Inorder successor of root
        }

    }
    return root;

}
int main(){
    int ch;
    int flag=0;
    struct node*root=NULL;
    do{
        printf("\nEnter your choice:\n");
        printf("1)Insert a node\n2)Delete a node\n3)Inorder\n4)Preorder\n5)Postorder\n6)Exit\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                {
                    int value;
                    printf("\nEnter the value you want to insert:\n");
                    scanf("%d",&value);
                    if(root==NULL){
                        root=Creation(value);
                    }
                    else{
                        Insertion(value,root);
                    }
                    printf("Current Status:\n");
                    printf("Inorder:\n");
                    Inorder(root);
                    break;
                }
            case 2:
                {
                    int value;
                    printf("Enter the value you want to Delete:\n");
                    scanf("%d",&value);
                    if(Search(root,value)==1){
                        printf("Element found!Now deleting %d\n",value);
                        root=Deletion(root,value);
                    }
                    else{
                        printf("Element not found!\n");
                    }
                    printf("Current Status:\n");
                    printf("Inorder:\n");
                    Inorder(root);
                    printf("\n");
                    break;
                }
            case 3:
                {
                    printf("\nInorder:\n");
                    Inorder(root);
                    break;
                }
            case 4:
                {
                    printf("\nPreorder:\n");
                    Preorder(root);
                    break;
                }
            case 5:
                {
                    printf("\nPostorder:\n");
                    Postorder(root);
                    break;
                }
            case 6:
                {
                    printf("\nProgram finished!\n");
                    flag=1;
                    break;
                }
                default:
                {
                    printf("Invalid input\n");
                    break;
                }
        }
    }while(flag!=1);
    
    return 0;
}