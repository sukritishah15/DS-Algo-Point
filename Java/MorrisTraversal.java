import java.util.Random;
 
public class MorrisTraversal 
{
    static class Node{          //static class to represent node structure
        int data;               //to store data of each node
        Node left,right;        //to point to left and right child of the node respectively
        Node(int d){            //constructor for initialisation of each values
           this.data=d;
           this.left=null;
           this.right=null;
        }
    }
    public static void printInorder(Node root){
         if(root==null){             //if tree is empty
            return;   
         }
         Node curr=root;             //to point to the current node during traversal
         Node prev;                  //to point to the previous node encountered during traversal
         while(curr!=null){           
            if(curr.left==null){                           //if left child is not present 
               System.out.print(curr.data+" ");            //traverse current node 
               curr=curr.right;                            //and move toward it's right
            }else{
               prev=curr.left;
               while(prev.right!=null && prev.right!=curr){   //to point to inorder predecessor of current node
                    prev=prev.right;
               }
               if(prev.right==null){
                  prev.right=curr;            //to make the current node as
                  curr = curr.left;           //right child of it's inorder predecessor
               }else{
                  prev.right=null;           //fix the right child of prev
                  System.out.print(curr.data+" ");
                  curr=curr.right;
               }
            }   
         }
    }
    public static void main(String args[]){
       Node root = new Node(1);
       root.left = new Node(2);
       root.right = new Node(3);
       root.left.left = new Node(4);
       root.left.right = new Node(5);
       root.right.left = new Node(6);
       root.right.right = new Node(7);
       printInorder(root);
    }
}
/*  
-:Sample Input Tree:-
                   1
                  / \
                 2   3
                / \ / \
               4  5 6  7
-:Sample Output:-
4 2 5 1 6 3 7
-:Time Complexity:-
O(n) where n is the number of nodes in the given tree
-:Space Complexity:-
O(1)    
*/