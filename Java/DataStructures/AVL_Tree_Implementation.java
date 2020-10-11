package Java.DataStructures;

import java.util.Scanner;

class AVL_Tree_Implementation {
    //Node class to make nodes as class objects.
    class Node{
        int key, height;
        Node left, right;
        //Constructor to define values in Node.
        Node(int d){
            key = d;
            height = 1;
        }
    }
    Node root;
    
    //Finds the height of a given node.
	int height(Node N){
		if (N == null)
			return 0;
		return N.height;
    }
    
    //Find the maximum of the two heights given.
	int max(int a, int b){
		return (a > b) ? a : b;
    }
    
    //Perform right rotation on the given node.
	Node rightRotate(Node y){
		Node x = y.left;
        Node T2 = x.right;
		x.right = y;
		y.left = T2;
		y.height = max(height(y.left), height(y.right)) + 1;
		x.height = max(height(x.left), height(x.right)) + 1;
		return x;
    }
    
    //Perform left rotation on the given node.
	Node leftRotate(Node x){
		Node y = x.right;
		Node T2 = y.left;
		y.left = x;
		x.right = T2;
		x.height = max(height(x.left), height(x.right)) + 1;
		y.height = max(height(y.left), height(y.right)) + 1;
		return y;
    }
    
    //Check if the current node is balanced.
	int getBalance(Node N){
		if (N == null)
			return 0;
		return height(N.left) - height(N.right);
    }
    
    //Find the node with the minimum value.
    Node minValueNode(Node node){
		Node current = node;
		while (current.left != null)
		current = current.left;
		return current;
    }

    //Inserting a node into the existing tree.
	Node insert(Node node, int key){
		if (node == null)
			return (new Node(key));
		if (key < node.key)
			node.left = insert(node.left, key);
		else if (key > node.key)
			node.right = insert(node.right, key);
		else
            return node;
		node.height = 1 + max(height(node.left), height(node.right));
		int balance = getBalance(node);
		if (balance > 1 && key < node.left.key)
			return rightRotate(node);
		if (balance < -1 && key > node.right.key)
			return leftRotate(node);
		if (balance > 1 && key > node.left.key){
			node.left = leftRotate(node.left);
			return rightRotate(node);
		}
		if (balance < -1 && key < node.right.key){
			node.right = rightRotate(node.right);
			return leftRotate(node);
        }
		return node;
	}
    
    // Deletion of node from the tree.
	Node deleteNode(Node root, int key){
		if (root == null)
			return root;
		if (key < root.key)
			root.left = deleteNode(root.left, key);
		else if (key > root.key)
			root.right = deleteNode(root.right, key);
		else{
			if ((root.left == null) || (root.right == null)){
				Node temp = null;
				if (temp == root.left)
					temp = root.right;
				else
					temp = root.left;
				if (temp == null){
					temp = root;
					root = null;
				}
				else
					root = temp;
			}
			else{
				Node temp = minValueNode(root.right);
				root.key = temp.key;
				root.right = deleteNode(root.right, temp.key);
			}
		}
		if (root == null)
			return root;
		root.height = max(height(root.left), height(root.right)) + 1;
        int balance = getBalance(root);
        
        //4 possible rotations if the root is unbalanced.
        //Left-Right rotation
		if (balance > 1 && getBalance(root.left) >= 0)
            return rightRotate(root);
            
        //Left-Left rotation
		if (balance > 1 && getBalance(root.left) < 0){
			root.left = leftRotate(root.left);
			return rightRotate(root);
        }
        
        //Right-Left rotation
		if (balance < -1 && getBalance(root.right) <= 0)
            return leftRotate(root);
            
        //Right-Right rotation
		if (balance < -1 && getBalance(root.right) > 0){
			root.right = rightRotate(root.right);
			return leftRotate(root);
		}
		return root;
    }

    // Preorder traversal to print the nodes in the tree.
	void preOrder(Node node){
		if (node != null){
			System.out.print(node.key + " ");
			preOrder(node.left);
			preOrder(node.right);
        }
	}
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        AVL_Tree_Implementation tree = new AVL_Tree_Implementation();
        System.out.println("Enter the number of nodes you want to enter.");
        int numOfNodes = sc.nextInt();
        System.out.println("Enter the individual nodes separated by spaces.");
        for(int i=0; i < numOfNodes;i++ ){
            int key = sc.nextInt();
            tree.root = tree.insert(tree.root, key);
        }
	System.out.println("Preorder traversal of constructed tree is : ");
        tree.preOrder(tree.root);
	System.out.println("");
        System.out.println("Enter the node to be deleted : ");
        int delKey = sc.nextInt();
	tree.root = tree.deleteNode(tree.root, delKey);
	System.out.println("");
	System.out.println("Preorder traversal after deletion of 10 :");
        tree.preOrder(tree.root);
        sc.close();
	}
}

/*
Sample Input Output - 
Enter the number of nodes you want to enter.
12

Enter the individual nodes separated by spaces.
9 8 7 6 4 2 3 17 19 22 23 13

Preorder traversal of constructed tree is : 
8 6 3 2 4 7 17 9 13 22 19 23 

Enter the node to be deleted : 
13

Preorder traversal after deletion of 10 :
8 6 3 2 4 7 17 9 22 19 23


Complexity - 
Insertion - Log(n)
Deletion - Log(n)

This is because for a BST, both of them are O(height) where height refers to the height of the tree. 
But, when we talk about AVL Tree, since it is balanced, we check log(height) times only.
*/
