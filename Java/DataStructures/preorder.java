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

    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(DataStructures.Node node)
    { 
        if (node == null) 
            return; 

        /* first print data of node */
        System.out.print(node.key + " "); 

        /* then recur on left sutree */
        printPreorder(node.left); 

        /* now recur on right subtree */
        printPreorder(node.right); 
    } 

    // Wrappers over above recursive functions 
    void printPreorder()   {     printPreorder(root);  } 

    // Driver method 
    public static void main(String[] args) 
    { 
        Algorithms.BinaryTree tree = new Algorithms.BinaryTree();
        tree.root = new DataStructures.Node(1);
        tree.root.left = new DataStructures.Node(2);
        tree.root.right = new DataStructures.Node(3);
        tree.root.left.left = new DataStructures.Node(4);
        tree.root.left.right = new DataStructures.Node(5);

        System.out.println("Preorder traversal of binary tree is "); 
        tree.printPreorder(); 

    } 
} 

/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Prerder traversal of binary tree is
          1 2 4 5 3
*/
