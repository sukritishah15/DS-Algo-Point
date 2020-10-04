//Preorder traversal for tree in C++
#include <iostream>
using namespace std;

//Structure for a node of the tree
struct Node{
    
    //Each node should have left and right pointers and a variable for data
    struct Node* left;
    struct Node* right;
    int val;
    
    //Parameterized constructor
    Node(int data){
        val = data;
        left = right = NULL;
    }
};

//Function for preorder traversal of a tree
void Preorder(struct Node* node){
    
    if (node == NULL) {
        return; 
    }
    cout<<node->val<<" ";
    Preorder(node->left);
    Preorder(node->right);
}

int main(){
    //Creating a tree with the following structure
    //          1      (root)
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	cout<<"Preorder traversal:"<<"\n";
	Preorder(root);
	
	return 0;
}

/*
Trees primarily consist of individual elements called nodes each of which have a left and right pointer, pointing
to other nodes in the structure and a data field to store some data.
Trees can be travered in 3 ways:
1.Preorder
2.Inorder
3.Postorder

In Preorder traversal the root node is visited first, then the left subtree and then the right subtree.

Application:
Used to create prefix expression from expression tree.

Time Complexity: O(n)
Space Complexity: O(1)

Sample I/O:

Input(Given in main):
    //          1      (root)
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

Output:
Preorder traversal:
1 2 4 5 3 6 7 

*/
