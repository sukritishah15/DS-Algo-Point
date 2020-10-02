#include <bits/stdc++.h>

using namespace std;

/* a node of doubly linked list */
class Node {

public:
    int data;
    Node *next_node;
    Node *prev_node;

};

/* Function to swap two elements */
void swap ( int* a, int* b ) 
{ 
    int t = *a; *a = *b; *b = t; 
}

// Function to find last node of the linked list
Node *lastNode(Node *root)
{
    while (root && root->next_node)
        root = root->next_node;

    return root;
}

/* Arrange all the elements of the linked list as per the pivot element */
Node* partition(Node *l, Node *h)
{
    // set h element as pivot
    int x = h->data;
    Node *i = l->prev_node;

    // Similar to from j=l to h-1
    for (Node *j = l; j != h; j = j->next_node)
    {
        if (j->data <= x)
        {
            // Similar to i++
            i = (i == NULL)? l : i->next_node;
            swap(&(i->data), &(j->data));
        }
    }

    i = (i == NULL)? l : i->next_node;
    swap(&(i->data), &(h->data));
    return i;
}

/* Recursive implementation of quicksort for linked list */
void _quickSort(Node* l, Node *h)
{
    if (h != NULL && l != h && l != h->next_node)
    {
        Node *p = partition(l, h);
        _quickSort(l, p->prev_node);
        _quickSort(p->next_node, h);
    }

}

// Main function: It calls the _quickSort() method

void quickSort(Node *head)
{
    // Find the last node
    Node *h = lastNode(head);
    // Call recursive QuickSort
    _quickSort(head, h);
}

// Function to print the elements of array
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next_node;
    }
    cout << endl;
}

/* Function of insertion in the beginning*/
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;  /* allocate node */
    new_node->data = new_data;
    /* Here, prev is always NULL */
    new_node->prev_node = NULL;
    /* link the old list off the new node */
    new_node->next_node = (*head_ref);
    /* change prev(head) to new node*/
    if ((*head_ref) != NULL) (*head_ref)->prev_node = new_node;
    /* Now, move the head pointing to the new node */
    (*head_ref) = new_node;
}

/* Driver code */
int main()
{
    Node *a = NULL;

    push(&a, 9);

    push(&a, 25);

    push(&a, 11);

    push(&a, 6);

    push(&a, 2);

    cout << "Linked List before sorting \n";

    printList(a);

    quickSort(a);

    cout << "Linked List after sorting \n";

    printList(a);
    return 0;
}

// Output: 
// Linked List before sorting 
// 2 6 11 25 9 
// Linked List after sorting 
// 2 6 9 11 25 