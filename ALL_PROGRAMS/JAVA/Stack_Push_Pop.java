import java.util.*;
class staimp{
    int size;
    int top;
    int [] a;
    staimp(int size,int [] a){
        this.size=size;
        this.top=-1;
        this.a=a;
    }
    void stpop(){
        if(top==-1){
            System.out.println("Stack is underflowing");
        }
        else{
            top--;
            System.out.println("The popped element="+a[top+1]);
        }

    }
    void stpush(int element){
        if(top==size-1){
            System.out.println("Stack is overflowing");
        }
        else{
            top++;
            a[top]=element;
        }
    }


}
public class DsaExp1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of stack:");
        int n=sc.nextInt();
        int [] arr= new int[n];
        staimp s= new staimp(n,arr);
        for(int i=0;i<arr.length;i++){
            s.stpush(i);
        }
        System.out.println("Stack before pushing or popping");
        System.out.println("After pushing extra element");
        s.stpush(8);
        System.out.println();
        for (int j : arr) {
            System.out.println(j);
        }
        s.stpop();
        s.stpop();
        s.stpop();
        s.stpop();
        s.stpop();



    }
}
