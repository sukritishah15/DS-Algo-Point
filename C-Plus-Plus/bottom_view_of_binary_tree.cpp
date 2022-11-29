// Bottom view of a Binary Tree Solution from Scratch

// Problem Statement: Bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

#include<bits/stdc++.h>
using namespace std;

//Creating structure of Node
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

//This functions returns a pointer to a node having value equal to k. Right and Left pointers are assigned NULL values.
TreeNode* get_new_node(int k)
{
    TreeNode* temp = new TreeNode();
    temp->val = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Function to print the bottom view of binary tree
void print_bottom_view(TreeNode* root, map<int,int>& m1)
{
    //Return if there is no node present in the tree
    if(root==NULL)
        return;

    //We'll be doing level order traversal of the tree so that the nodes are visited in vertical order 
    queue<pair<TreeNode*,int>> q1;
    q1.push({root,0});

    while(!q1.empty())
    {
        //Every time we encounter a node during level order traversal, we'll be saving the value of node as value of it's corresponding key, i.e. its vertical level in map
        m1[q1.front().second]=q1.front().first->val;

        //Adding Right Node to queue if it's not NULL
        if(q1.front().first->right!=NULL)
            q1.push({q1.front().first->right,q1.front().second+1});
        
        //Adding Left Node to queue if it's not NULL
        if(q1.front().first->left!=NULL)
            q1.push({q1.front().first->left,q1.front().second-1});

        //Node popped from the queue
        q1.pop();
    }

}

int main()
{
    //Creating the tree
    TreeNode* root = get_new_node(7);
    root->right = get_new_node(1);
    root->left = get_new_node(4);
    root->left->right = get_new_node(9);
    root->left->right->right = get_new_node(5);
    root->left->right->left = get_new_node(8);
    root->left->right->right->right = get_new_node(10);

    //Map having KEY as the vertical level and VALUE as value of the node
    map<int, int> m1;
    print_bottom_view(root,m1);

    //Printing the bottom view of the tree
    cout<<"Printing the bottom view of the tree: ";
    for(auto it=m1.begin(); it!=m1.end(); it++)
        cout<<it->second<<" ";

    return 0;
}

/*
Sample input-output statement will very from tree-to-tree.
Still if we consider the same tree and check for the top view, Output is:
Printing the bottom view of the tree: 8 9 5 10
*/

/* 
Time Complexity: O(N), where N is the number of nodes in the tree
Space Complexity: O(N), where N is the number of nodes in the tree
*/
