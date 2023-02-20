import java.util.*;
class Queue{
    int rear;
    int front;
    int [] a;
    int size;

    Queue(int size){
        this.size=size;
        this.front=0;
        this.rear=0;
        this.a=new int[size];
    }
    void Deq(){
        if(isEmpty()){
            System.out.println("Underflow State");
        }
        else {
            System.out.println("Dequeued:" + a[(front+1)%size]);
            front=(front+1)%size;   //%size is done to avoid going beyond the length of queue
        }
    }

    void Enq(int element){  //Enqueue operation
        if(isFull()){
            System.out.println("Overflow state");
        }
        else {
            rear=(rear+1)%size;     //%size is done to avoid going beyond the length of queue
            a[rear] = element;
            System.out.println("Enqueued:" + element);
        }
    }

    void getFront(){
        if(!isEmpty()){
            System.out.println(a[(front+1)%size]);
        }
        else if(isEmpty()){
            System.out.println("Queue is Empty");
        }
    }

    void display(){
        int f=front;
        if(!isEmpty()){
            while(f!=rear){
                f=(f+1)%size;
                System.out.print(a[f]+" ");
            }
        }
        else{
            System.out.println("Queue is empty");
        }
    }

    void getRear(){
        if(!isEmpty()){
            System.out.println(a[rear]);
        }
        else if(isEmpty()){
            System.out.println("Queue is Empty");
        }

    }

    boolean isEmpty(){
        return front==rear;
    }

    boolean isFull(){
        return (rear+1)%size==front;
    }
}
public class QueueFunctions{
    public static void main(String [] args){

        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the Queue");
        int n=sc.nextInt();

        Queue q=new Queue(n);


        int flag=0;
        do{
            System.out.println();
            System.out.println("Menu");
            System.out.println("1)Enqueue");
            System.out.println("2)Dequeue");
            System.out.println("3)Tell the Front-most element");
            System.out.println("4)Tell the Rearmost element");
            System.out.println("5)Exit");

            int ch=sc.nextInt();
            switch (ch) {
                case 1 -> {
                    System.out.println("Enter the element you want to enqueue");
                    int element = sc.nextInt();
                    q.Enq(element);
                    System.out.println("Status after performing Enqueue operation");
                    q.display();
                }
                case 2 -> {
                    q.Deq();
                    System.out.println("Status after performing Dequeue operation");
                    q.display();
                }
                case 3 -> {
                    System.out.println("Current Status");
                    q.display();
                    System.out.println();
                    System.out.println("The Front most element is ");
                    q.getFront();
                }
                case 4 -> {
                    System.out.println("Current Status");
                    q.display();
                    System.out.println();
                    System.out.println("The Rear most element");
                    q.getRear();
                }
                case 5 -> {
                    System.out.println("Program finished");
                    flag = 1;
                }
                default -> System.out.println("Invalid choice");
            }

        }while(flag!=1);

    }
}
