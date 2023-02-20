import java.util.Scanner;
class stackimp{
    int size;
    int top;
    char [] a;
    stackimp(int size){
        this.size=size;
        this.top=-1;
        this.a=new char[size];
    }

    void pop(){
        if(isEmpty()){
            System.out.println("Stack is underflowing");
            System.exit(1);
        }
        else {
            System.out.println("Popped:" + a[top]);
            top--;
        }
    }
    void push(char element){
        if(isFull()){
            System.out.println("Stack is overflowing");
            System.exit(1);
        }
        else {
            top++;
            a[top] = element;
            System.out.println("Pushed:" + a[top]);
        }
    }
  char getTop(){
        if(!isEmpty()){
            return a[top];
        }
        return '\0';
    }
    boolean isEmpty(){
        return top == -1;
    }
    boolean isFull(){
        return top==size-1;
    }
}
public class InfixToPostfix {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        StringBuilder postfix= new StringBuilder();
        char ch;
        System.out.println("Enter the string:");
        String infix=sc.next();

        stackimp s= new stackimp(infix.length()); // Stackimp class object created with input parameter as length

        for (int i=0;i<infix.length();i++){// For loop for traversing the entire string

            ch=infix.charAt(i);
            if(s.isEmpty() && i!=infix.length()-1 && !Character.isAlphabetic(ch)){
                s.push(ch);
            }
           else if(ch=='('  && !s.isEmpty()){
                s.push(ch);
            }
           else if(ch=='^' && s.getTop()!='^' && !s.isEmpty()){
               s.push(ch);
            }
           else if(ch=='^' && s.getTop()=='^' && !s.isEmpty()){
                postfix.append(s.getTop());
                s.pop();
                while (s.getTop()=='^'){        //Checks if there is a operator of equal precedence
                    postfix.append(s.getTop());
                    s.pop();
                }
                s.push(ch);
            }
           else if(Character.isAlphabetic(ch)){
                System.out.println("Chracter entered is "+ch);
                postfix.append(ch);
            }
           else if((ch=='*' || ch=='/') && s.getTop()!='^' && !s.isEmpty()){
                s.push(ch);
            }
           else if((ch=='*' || ch=='/') && s.getTop()=='^' && !s.isEmpty()) {
                postfix.append(s.getTop());
                s.pop();
                while((s.getTop()=='*' || s.getTop()=='/' || s.getTop()=='^')&& !s.isEmpty()){ //Checks if there is a operator of Higher of equal precedence
                    postfix.append(s.getTop());
                    s.pop();
                }
                s.push(ch);
            }
            else if((ch=='-'|| ch=='+') && (s.getTop()=='^' ||s.getTop()=='*'|| s.getTop()=='/'||s.getTop()=='+' || s.getTop()=='-' )&& !s.isEmpty()) {
                postfix.append(s.getTop());
                s.pop();
                while((s.getTop()=='+' || s.getTop()=='-'||s.getTop()=='^' ||s.getTop()=='*'|| s.getTop()=='/') && !s.isEmpty()){
                    postfix.append(s.getTop()); //Checks if there is a operator of Higher of equal precedence
                    s.pop();
                }
                s.push(ch);
            }
           else if((ch=='-'|| ch=='+') && (s.getTop()!='^' ||s.getTop()!='*'|| s.getTop()!='/' )&& !s.isEmpty()){
                s.push(ch);
            }
           else if(ch==')' && !s.isEmpty()){
                System.out.println("Popped:)");
                while (s.getTop()!='(') {
                    postfix.append(s.getTop());
                    s.pop();
                }
                s.pop();
            }
        }
        if(!s.isEmpty()){       // If at the end the stack is not empty it empty's the stack and prints the operators
            while (!s.isEmpty()) {
                postfix.append(s.getTop());
                s.pop();
            }
        }
        System.out.println("Final answer: ");
        System.out.println(postfix);
    }
}

