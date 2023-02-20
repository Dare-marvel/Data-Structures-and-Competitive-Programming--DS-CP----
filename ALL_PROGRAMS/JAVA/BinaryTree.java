
public class BinaryTree{
    public static int Node_count=0;
    class Node{
        int data;
        Node left,right;
        public Node(int data){
            this.data=data;
            left=right=null;
        }
    }
    Node root;
    public BinaryTree(){
        root= null;
    }
    public BinaryTree(int data){
        root= new Node(data);
    }


    Node Insertion(Node root,int data){
        Node_count++;
        if(root==null){
            System.out.println("root==null");
            return new Node(data);
        }
        else if (root.left==null) {
            System.out.println("root.left==null");
            root.left=new Node(data);
        }
        else if(root.right==null){
            System.out.println("root.right==null");
            root.right=new Node(data);
        }
        else{
            root.left=Insertion(root.left,data);
        }
        return root;
    }

    void Insert(int data){
        root=Insertion(root,data);
    }
    void InorderRec(Node root){

        if(root!=null){
            InorderRec(root.left);
            System.out.print(root.data+" ");
            InorderRec(root.right);
        }
    }

    void PreorderRec(Node root){

        if(root!=null){
            System.out.print(root.data+" ");
            InorderRec(root.left);
            InorderRec(root.right);
        }
    }
    void Inorder(){
        System.out.println("Inorder Travesal");
        InorderRec(root);
    }

    void Preorder(){
        System.out.println("Preorder Travesal");
        PreorderRec(root);
    }

    public static void main(String[] args) {
    BinaryTree tree=new BinaryTree();
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);

    tree.Inorder();
    System.out.println();
    tree.Preorder();

    }
}
