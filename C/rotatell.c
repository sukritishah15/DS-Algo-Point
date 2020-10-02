  
#include <stdio.h> 
#include <stdlib.h> 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// This function rotates a linked list counter-clockwise and 
// updates the head. The function assumes that k is smaller 
// than size of linked list. It doesn't modify the list if 
// k is greater than or equal to size 
void rotate(struct Node** head_ref, int k) 
{ 
    if (k == 0) 
        return; 
  
    // Let us understand the below code for example k = 4 and 
    // list = 10->20->30->40->50->60. 
    struct Node* current = *head_ref; 
  
    // current will either point to kth or NULL after this loop. 
    // current will point to node 40 in the above example 
    int count = 1; 
    while (count < k && current != NULL) { 
        current = current->next; 
        count++; 
    } 
  
    // If current is NULL, k is greater than or equal to count 
    // of nodes in linked list. Don't change the list in this case 
    if (current == NULL) 
        return; 
  
    // current points to kth node. Store it in a variable. 
    // kthNode points to node 40 in the above example 
    struct Node* kthNode = current; 
  
    // current will point to last node after this loop 
    // current will point to node 60 in the above example 
    while (current->next != NULL) 
        current = current->next; 
  
    // Change next of last node to previous head 
    // Next of 60 is now changed to node 10 
    current->next = *head_ref; 
  
    // Change head to (k+1)th node 
    // head is now changed to node 50 
    *head_ref = kthNode->next; 
  
    // change next of kth node to NULL 
    // next of 40 is now NULL 
    kthNode->next = NULL; 
} 
  
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
/* Function to print linked list */
void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  
/* Driver program to test above function*/
int main(void) 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    // create a list 10->20->30->40->50->60 
    for (int i = 60; i > 0; i -= 10) 
        push(&head, i); 
  
    printf("Given linked list \n"); 
    printList(head); 
    rotate(&head, 4); 
  
    printf("\nRotated Linked list \n"); 
    printList(head); 
  
    return (0); 
} 
/*
Time Complexity -O(N),N is number of nodes.
Space Complexity -O(1)
Input- Taken in the code
Output-
Given linked list
10  20  30  40  50  60
Rotated Linked list
50  60  10  20  30  40
*/
