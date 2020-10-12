package Java.Algorithms;

class Node
{ 
    int key; 
    Node left, right; 

    public Node(int item) 
    { 
        key = item; 
        left = right = null; 
    } 
}

class BinaryTree 
{ 
    // Root of Binary Tree 
    Node root; 

    BinaryTree() 
    { 
        root = null; 
    } 



    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(Node node) 
    { 
        if (node == null) 
            return; 

        /* first recur on left child */
        printInorder(node.left); 

        /* then print the data of node */
        System.out.print(node.key + " "); 

        /* now recur on right child */
        printInorder(node.right); 
    } 



    // Wrappers over above recursive functions 
    void printInorder()    {     printInorder(root);   } 


    // Driver method 
    public static void main(String[] args) 
    { 
        BinaryTree tree = new BinaryTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 


        System.out.println("\nInorder traversal of binary tree is "); 
        tree.printInorder(); 
     } 
} 

/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Inorder traversal of binary tree is
          4 2 5 1 3 
*/
