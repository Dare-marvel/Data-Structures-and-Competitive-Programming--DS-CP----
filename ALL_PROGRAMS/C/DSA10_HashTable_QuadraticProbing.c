#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct HashTable
{
    int * arr;
    int size;
};

int getHashfn(int key , struct HashTable * h){
    return key % (h->size);
}

void Initialize(struct HashTable * h){
    for (int i = 0; i < h->size; i++)
    {
        h->arr[i]=-1;
    }
}

void PrintTable(struct HashTable * h){
    printf("-------------------\n");
    printf("|  Index  |  Key  |\n");
    printf("-------------------\n");
    for (int i = 0; i < h->size; i++)
    {
        if(h->arr[i]!=-1){
            printf("|   %d     |   %2d  |\n",i,h->arr[i]);
        }
        else{
            printf("|   %d     |  NULL |\n",i);
        }
    }
    printf("-------------------\n");
}

void Insertion(struct HashTable * h, int key,int start_ind){
    int i,index;
    for (i = 0; i < h->size; i++)
    {
        index=(start_ind + i*i)%h->size;
        if(h->arr[index]==-1){
            h->arr[index]=key;
            PrintTable(h);
            break;
        }
        else{
            printf("Collision occured at index: %d\n",index);
        }
    }
    if(i==h->size){
        printf("Element can't be inserted!\n");
    }
    
}


int main()
{
int size;
struct HashTable * h=(struct HashTable *)malloc(sizeof(struct HashTable));

printf("Enter the size of HashTable\n");
scanf("%d",&size);

h->size=size;
h->arr=(int *)malloc(h->size * sizeof(int));

Initialize(h);

int num_ele=100000;

while(num_ele>h->size){
    printf("Enter the number of elements u want to insert in Hash Table\n");
    scanf("%d",&num_ele);
    if(num_ele>h->size){
        printf("Please enter the number of elements less the size of hash table\n");
    }
}

int ele;
for (int i = 0; i < num_ele; i++) {
            printf("Enter the key\n");
            scanf("%d",&ele);
            int start_ind=getHashfn(ele,h);
            Insertion(h,ele,start_ind);
        }   

return 0;
}