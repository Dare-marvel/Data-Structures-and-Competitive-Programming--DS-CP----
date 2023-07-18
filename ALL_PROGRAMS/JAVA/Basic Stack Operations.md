## Explanation
This Java code implements a stack using an array. Here's how it works:

1. A `staimp` class is defined with three instance variables: `size`, `top`, and `a`.
2. The `staimp` class has a constructor that takes an integer size and an integer array as arguments, initializes the instance variables, and sets the `top` variable to -1 to indicate that the stack is empty.
3. The `stpop` method removes the element at the top of the stack and prints it. If the stack is empty, it prints a "Stack is underflowing" message.
4. The `stpush` method takes an integer element as an argument and adds it to the top of the stack. If the stack is full, it prints a "Stack is overflowing" message.
5. In the `main` method, a new `staimp` object is created with a given size and array.
6. Elements are pushed onto the stack using a for loop and the `stpush` method.
7. An extra element is pushed onto the stack using the `stpush` method, causing an "Stack is overflowing" message to be printed.
8. The elements in the stack are printed using a for-each loop.
9. Elements are popped from the stack using the `stpop` method.

## Time and Space Complexity:
### `Time Complexity`:
The time complexity of pushing and popping elements in a stack is O(1), as these operations take constant time.

### `Space Complexity`:
The space complexity is O(n), where n is the size of the stack.

## Code:
```java
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
```
