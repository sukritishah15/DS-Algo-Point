/*The function should return a single integer denoting the height of the binary tree.
For example, the following binary tree is of height 2:
            4
          /   \
        2      6
      /   \   /  \
     1     3  5   7   
     
the solution is to find the max of count of the node at left and right of each node and add 1 for the root node
recursively.

recursively do:
1. If tree is empty then return 0
2. Else
     (i) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (ii) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (iii) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (iv) Return max_depth
     
     */


#include <bits/stdc++.h> 
using namespace std; 


//class for node.
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};

/* function that allocates a new created node with the  
given data and left and right pointers to be NULL. 
basically create a new node.
*/
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
}  

int height(node* root) {
        if(root == NULL){
            return -1;
        }
        int l=height(root->left);
        
        int r=height(root->right);
        
        return max(l,r)+1;
    }

int main()  
{  
    node *root = newNode(4);  
    root->left = newNode(2);  
    root->right = newNode(6);  
    root->left->left = newNode(1);  
    root->left->right = newNode(3);  
    root->right->left = newNode(5);
    root->right->right = newNode(7);

      
    cout << "Height of tree is " << height(root);  
    return 0;  
}  


/*
    Time Complexity: O(n)
    Space Complexity: O(1)
    
    input:
    *internal input is given in the program itself, the input is a binary tree given in the example
    above.

    output:
    Height of tree is 2
    
    */
    