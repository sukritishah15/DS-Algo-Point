package Algorithms;

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



    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(DataStructures.Node node)
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
        tree.root = new DataStructures.Node(1);
        tree.root.left = new DataStructures.Node(2);
        tree.root.right = new DataStructures.Node(3);
        tree.root.left.left = new DataStructures.Node(4);
        tree.root.left.right = new DataStructures.Node(5);


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
