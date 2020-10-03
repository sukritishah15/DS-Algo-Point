#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
class Tree
{
public:
    struct Node *root;
    struct Node *createNode(int key);
    void postOrder(struct Node *root);
    Tree()
    {
        root = NULL;
    }
};
struct Node *Tree::createNode(int key)
{
    struct Node *newnode = new Node;
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}
void Tree::postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
/*
Sample I/O:

    Tree tree_test;
    struct node *newnode = tree_test.createnode(11);
    newnode->left = tree_test.createnode(12);
    newnode->right = tree_test.createnode(6);
    newnode->left->left = tree_test.createnode(8);
    newnode->left->right = tree_test.createnode(41);
    newnode->right->left = tree_test.createnode(43);
    newnode->right->right = tree_test.createnode(25);
            Tree Structure is :
                 11
                /  \
               12   6
              / \  / \
             8  41 43 25
    Post Order Traversal of tree is:
    8 41 12 43 25 6 11  
    Time Complexity : O(n), where n is number of nodes
    Space Complexity : O(1) or O(n) if size of stack for function call is included
*/