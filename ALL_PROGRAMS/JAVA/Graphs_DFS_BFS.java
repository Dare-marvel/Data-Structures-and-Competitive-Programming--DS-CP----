import java.util.*;

class Graph{
    public static int time =1;
    int ver;
    static boolean[] visitedbfs;
    static boolean[] visiteddfs;
    LinkedList <Integer> adj [];


    Graph(int ver){
        this.ver=ver;
        adj= new LinkedList[ver];
        visitedbfs= new boolean[ver];
        visiteddfs= new boolean[ver];


        for(int i=0;i<ver;i++){
            adj[i]=new LinkedList<Integer>();
        }
    }

    void Add(int v,int w){
        adj[v].add(w);
        adj[w].add(v);
    }

    void DFS(int ver, int[] start, int[] end){

        start[ver]=time;
        time++;

        visiteddfs [ver]=true;
        System.out.print(ver +" ");

        Iterator <Integer> it= adj[ver].listIterator();
        while(it.hasNext()){
            int vis=it.next();
            if(!visiteddfs[vis]){
                DFS(vis,start,end);
            }
        }

        end[ver]=time;
        time++;
    }
    void print(){
        System.out.println("Adjacency List representation of Graph:");
        for (int i = 1; i < ver; i++) {
            System.out.print(i+ ":");
            for (int x : adj[i]) {
                System.out.print(x+ " ");
            }
            System.out.println();
        }
    }

    void BFS(int src, int[] level){
        LinkedList<Integer> queue = new LinkedList();
        visitedbfs[src] =true;
        level[src]=0;

        queue.add(src);

        while(queue.size()!=0){
            src=queue.poll();
            System.out.print(src +" ");


            Iterator<Integer> It= adj[src].listIterator();
            while(It.hasNext()){
                int neigh=It.next();
                if(!visitedbfs[neigh]){
                    level[neigh]=level[src]+1;
                    queue.add(neigh);
                    visitedbfs[neigh]=true;
                }
            }
        }
    }
}

public class DSA8{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of vertices:");
        int ver= sc.nextInt();
        Graph g = new Graph(ver+1);

        System.out.println("Enter the number of edges:");
        int edge=sc.nextInt();

        int[] start =new int [ver+1];
        int[] end =new int [ver+1];
        int[] level =new int [ver+1];

        for(int i=0;i<edge;i++){
            System.out.println("Enter the first vertex");
            int src=sc.nextInt();
            System.out.println("Enter the second vertex");
            int des=sc.nextInt();
            g.Add(src, des);
        }

        System.out.println("Representation of graph");
        g.print();
        System.out.println("Enter the vertex from where you want to start traversal:");;
        int startver=sc.nextInt();
        System.out.println();

        System.out.println("DFS TRAVERSAL");
        g.DFS(startver,start,end);
        System.out.println();

        for (int i = 1; i <= ver; i++)
            System.out.println("Vertex :" + i + " START TIME :"
                    + start[i] + " END TIME :" + end[i]);

        System.out.println();
        System.out.println("BFS TRAVERSAL:");
        g.BFS(startver,level);
        System.out.println();

        System.out.println("Vertex"+ " | " + "Level");
        System.out.println("---------------");
        for (int i = 1; i <= ver; i++)
            System.out.println("|  " + (i) + "   |   " + level[i]+"  |");
        System.out.println("---------------");
    }

}
