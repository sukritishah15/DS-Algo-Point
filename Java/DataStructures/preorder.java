package Java.DataStructures;

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

    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(Node node) 
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
        BinaryTree tree = new BinaryTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 

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
