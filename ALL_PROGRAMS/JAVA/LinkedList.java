import java.util.Scanner;

class MyLinkedList{
    Node head;
    static class Node{
        int data;
        Node next;

        public Node(int d){
            this.data=d;
            this.next=null;
        }
    }

   public void InsertAtFirst(int data){
        Node a=new Node(data);
        a.next=head;
        head=a;
    }

   public void InsertAtEnd(int data){
        Node a=new Node(data);
        if(head==null){
            head=a;
            return;
        }
        a.next=null;
        Node last=head;
        while(last.next!=null){
            last=last.next;
        }
        last.next=a;

    }
    void Display(){
        Node curr=head;
        System.out.println("Traversal of entire linked list");
        while(curr!=null){
            System.out.print(curr.data+" ");
            curr=curr.next;
        }
    }
}

public class LinkedList {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        MyLinkedList l1=new MyLinkedList();
        int flag=0;
        do {
            System.out.println("Enter your choice:");
            System.out.println("1)Insert At First");
            System.out.println("2)Insert At End");
            System.out.println("3)Exit");
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.println("Enter the element:");
                    int ele = sc.nextInt();
                    l1.InsertAtFirst(ele);
                    System.out.println("Current status:");
                    l1.Display();
                    System.out.println();
                    break;

                case 2:
                    System.out.println("Enter the element:");
                    int ele1 = sc.nextInt();
                    l1.InsertAtEnd(ele1);
                    System.out.println("Current status:");
                    l1.Display();
                    System.out.println();
                    break;

                case 3:
                    System.out.println("Program finished");
                    flag=1;
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }while (flag!=1);
    }
}
