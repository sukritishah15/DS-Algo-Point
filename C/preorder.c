#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 

     return(node); 
} 

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 

     /* first print data of node */
     printf("%d ", node->data);   

     printPreorder(node->left);   

     printPreorder(node->right); 
}     

int main() 
{ 
     struct node *root  = newNode(5); 
     root->left             = newNode(6); 
     root->right           = newNode(7); 
     root->left->left     = newNode(8); 
     root->left->right   = newNode(9);  

     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 

     getchar(); 
     return 0; 
} 
/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Prerder traversal of binary tree is
          5 6 8 9 7
*/
