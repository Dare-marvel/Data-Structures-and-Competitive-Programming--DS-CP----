#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int *arr;//Array to maintain the heap
    int size;//Total size of heap array
    int usize;//Used(Current) size of heap array
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isFull(struct Heap *h)
{
    if (h->usize == h->size - 1)
    {
        return 1;
    }
    return 0;
}

void Display(struct Heap *h)
{
    printf("\nDisplay of the Heap:\n");
    for (int i = 1; i <= h->usize; i++)
    {
        printf("%d ", (h->arr[i]));
    }
}

//Heapify Top-Down approach
void TDHeapify(struct Heap *h)
{
    //If size of heap is already 1 ,There is no need to heapify the tree as it is already heapified
    if (h->usize == 1)
    {
        return;
    }
    else
    {
        for (int i = 2; i <= h->usize; i++)
        {
            int curr_ind = i;
            // If parent is greater than current index min heap property gets violated , so we need to swap them
            while ((curr_ind > 1) && (h->arr[curr_ind] < h->arr[curr_ind / 2]))
            {
                swap(&(h->arr[curr_ind]), &(h->arr[curr_ind / 2]));
                curr_ind = curr_ind / 2;
            }
        }
    }
}

void Insertion(struct Heap *h, int data)
{
    if (isFull(h) == 1)
    {
        printf("Heap is full!,Can't insert anymore elements\n");
    }
    else
    {
        h->usize++;
        h->arr[h->usize] = data;
        TDHeapify(h);
    }
    Display(h);
}

int HeapSort(struct Heap *h, int sorted[])
{
    int count = 0;
    while (h->usize != 1)
    {
        count++;
        sorted[count] = h->arr[1];
        swap(&(h->arr[h->usize]), &(h->arr[1]));//Replace last element of heap with the first
        h->usize--;
        TDHeapify(h);//Heapify the tree
        Display(h);
    }
    count++;
    sorted[count] = h->arr[1];
    return count;
}
int main()
{
    struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
    int n;
    int element;

    printf("Enter the size of Heap array\n");
    scanf("%d", &n);
    h->size = n + 1;
    h->usize = 0;
    h->arr = (int *)malloc(h->size * sizeof(int));
    for (int i = 1; i < h->size; i++)
    {
        h->arr[i] = 0;
    }

    int sorted[n + 1];//Array to store the sorted elements
    int flag = 0;
    do
    {
        printf("Enter your choice:\n1)Insertion\n2)HeapSort\n3)Exit\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the element to be inserted:\n");
            scanf("%d", &element);
            Insertion(h, element);
            printf("\n");
        }
        else if (ch == 2)
        {
            Display(h);
            int count = HeapSort(h, sorted);
            printf("\nThe elements in sorted order\n");
            for (int i = 1; i <= count; i++)
            {
                printf("%d ", sorted[i]);
            }
            printf("\n");
        }
        else if (ch == 3)
        {
            printf("Program finished!\n");
            flag = 1;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    } while (flag != 1);
    
    return 0;
}
