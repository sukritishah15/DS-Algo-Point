package DataStructures;

class Node
{ 
    int key; 
    DataStructures.Node left, right;
  
    public Node(int item) 
    { 
        key = item; 
        left = right = null; 
    } 
} 
  
class BinaryTree 
{ 
    // Root of Binary Tree 
    DataStructures.Node root;
  
    BinaryTree() 
    { 
        root = null; 
    } 
  
    /* Given a binary tree, print its nodes according to the 
      "bottom-up" postorder traversal. */
    void printPostorder(DataStructures.Node node)
    { 
        if (node == null) 
            return; 
  
        // first recur on left subtree 
        printPostorder(node.left); 
  
        // then recur on right subtree 
        printPostorder(node.right); 
  
        // now deal with the node 
        System.out.print(node.key + " "); 
    } 
  
  
  
    // Wrappers over above recursive functions 
    void printPostorder()  {     printPostorder(root);  } 

  
    // Driver method 
    public static void main(String[] args) 
    { 
        Algorithms.BinaryTree tree = new Algorithms.BinaryTree();
        tree.root = new DataStructures.Node(1);
        tree.root.left = new DataStructures.Node(2);
        tree.root.right = new DataStructures.Node(3);
        tree.root.left.left = new DataStructures.Node(4);
        tree.root.left.right = new DataStructures.Node(5);
  
  
        System.out.println("\nPostorder traversal of binary tree is "); 
        tree.printPostorder(); 
    } 
} 
/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Postrder traversal of binary tree is
          4 5 2 3 1

*/
