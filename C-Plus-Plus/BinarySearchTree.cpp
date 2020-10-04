//Implement Binary Search Tree and Perform Operations : Insertion, Deletion, Searching (Issue #22)
//https://github.com/sukritishah15/DS-Algo-Point/issues/22
//Contributed by @tauseefmohammed2 : https://github.com/tauseefmohammed2

#include<iostream>
using namespace std;

class BinarySearchTree {
    
    struct BSTnode {
        int data;
        BSTnode* left;
        BSTnode* right;
    };

    BSTnode* root;

    //Function to Clear a Node
    BSTnode* clear(BSTnode* t) {
        if(t == NULL)
            return NULL;
        {
            clear(t->left);
            clear(t->right);
            delete t;
        }
        return NULL;
    }

    //Function to Insert a Node
    BSTnode* insert(int x, BSTnode* t)
    {
        if(t == NULL)
        {
            t = new BSTnode;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    //Function to Obtain the Node with the Minimum Value
    BSTnode* min(BSTnode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return min(t->left);
    }

    //Function to Obtain the Node with the Maximum Value
    BSTnode* max(BSTnode* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return max(t->right);
    }

    //Function to Delete/Remove a Node from the BST
    BSTnode* remove(int x, BSTnode* t) {
        BSTnode* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = min(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    //Function to Display Inorder Traversal of the BST
    void inorder_traversal(BSTnode* t) {
        if(t == NULL)
            return;
        inorder_traversal(t->left);
        cout << t->data << " ";
        inorder_traversal(t->right);
    }

    //Function to Search and Check whether a Given Node is Present in the BST or Not
    BSTnode* search(BSTnode* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return search(t->left, x);
        else if(x > t->data)
            return search(t->right, x);
        else
            return t;
    }

public:
    //Creating Corresponding Functions for the Object to Acccess Outside the Class
    BinarySearchTree() {
        root = NULL;
    }

    ~BinarySearchTree() {
        root = clear(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder_traversal(root);
        cout << endl;
    }

    void search(int x) {
        root = search(root, x);
        if(root == NULL)
            cout << endl << x <<" is Not Present in the BST";
        else
            cout<< endl << x <<" is Present in the BST";
    }
};

int main() {
    //Creating Object of BinarySearchTree Class
    BinarySearchTree t;

    //Inserts the Following Nodes into the BST
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);

    //Displays Inorder Traversal of BST
    t.display();

    //Remove 20 and 25 From the BST and Display Corresponding Inorder Traversal
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    
    t.search(15);
    return 0; 
}

/*
Output :
10 15 20 25 30                                                                                                          
10 15 25 30                                                                                                             
10 15 30                                                                                                                                                                                                                                      
15 is Present in the BST                                                                                                 
20 is Not Present in the BST

Time Complexity :
Insertion : O(h) [h = Height of BST]
Deletion : O(h) [h = Height of BST]
Searching : O(h) [h = Height of BST]

Space Complexity :
O(n) [n = Number of Nodes in BST]
*/
