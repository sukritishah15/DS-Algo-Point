#include <stdio.h>  
#include <stdlib.h>  
   
//Represent a node of binary tree  
struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  
   
//Represent the root of binary tree  
struct node *root = NULL;  
   
//createNode() will create a new node  
struct node* createNode(int data){  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    //Assign data to newNode, set left and right children to NULL  
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
   
//findHeight() will determine the maximum height of the binary tree  
int findHeight(struct node *temp){  
    //Check whether tree is empty  
    if(root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else {  
        int leftHeight = 0, rightHeight = 0;  
          
        //Calculate the height of left subtree  
        if(temp->left != NULL)  
            leftHeight = findHeight(temp->left);  
          
        //Calculate the height of right subtree  
        if(temp->right != NULL)  
            rightHeight = findHeight(temp->right);  
          
        //Compare height of left subtree and right subtree   
        //and store maximum of two in variable max  
        int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;  
          
        //Calculate the total height of tree by adding height of root  
        return (max + 1);  
    }  
}  
   
int main()  
{  
    //Add nodes to the binary tree  
    root = createNode(1);  
    root->left = createNode(2);  
    root->right = createNode(3);  
    root->left->left = createNode(4);  
    root->right->left = createNode(5);  
    root->right->right = createNode(6);  
    root->right->right->right= createNode(7);  
    root->right->right->right->right = createNode(8);  
     
    printf("Maximum height of given binary tree: %d", findHeight(root));  
    return 0;  
}  
