#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};


void push(Node **head_ref, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = (*head_ref);
	(*head_ref) = temp;
}

void deleteNode(struct Node **head_ref, int position) 
{ 	
	if (position<0)	return;

	// If linked list is empty 
	if (*head_ref == NULL) 
	return; 

	struct Node* temp = *head_ref; 

	// If position is 0 head needs to be removed 
	if (position == 0) 
	{ 
		*head_ref = temp->next;
		free(temp);
		return; 
	} 

	// Iterate to find previous node of the node to be deleted 
	for (int i=0; temp!=NULL && i<position-1; i++) 
		temp = temp->next; 

	// If position is more than size of LinkedList
	if (temp == NULL || temp->next == NULL) 
		return; 

	// Node temp->next is the node to be deleted 
	// Store pointer to the next of node to be deleted 
	struct Node *next = temp->next->next; 

	// Unlink the node from linked list 
	free(temp->next);  // Free memory 

	temp->next = next;  // Unlink the deleted node from list 
} 

void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " ";
		node = node->next; 
	} 
} 


int main()
{
	Node *head = NULL;
	int n;
	cout << "Enter size of LinkedList :- ";
	cin >> n;

	cout << "Enter elements in LinkedList :- " << endl;		
	for (int i = 0; i < n; i++){
		int val;
		cin >> val;
		push(&head, val);
	}

	int pos;
	cout << "Enter position of node to be deleted :- ";
	cin >> pos;

	cout << "Original Linked List :- " << endl; 
    printList(head); 
    
	deleteNode(&head, pos); 
    
	cout << "\nLinked List after Deletion at position :- " << endl; 
    printList(head);


	return 0;
}

/*

Problem Statement :- Remove Nth node of Linked List.

Sample Input/Output :- 

1).

Enter size of LinkedList :- 5
Enter elements in LinkedList :- 
1 2 3 4 5
Enter position of node to be deleted :- 3
Original Linked List :- 
5 4 3 2 1 
Linked List after Deletion at position :- 
5 4 3 1

2).

Enter size of LinkedList :- 5
Enter elements in LinkedList :- 
1 2 3 4 5
Enter position of node to be deleted :- 0
Original Linked List :- 
5 4 3 2 1 
Linked List after Deletion at position :- 
4 3 2 1

3).

Enter size of LinkedList :- 5
Enter elements in LinkedList :- 
1 2 3 4 5
Enter position of node to be deleted :- 4
Original Linked List :- 
5 4 3 2 1 
Linked List after Deletion at position :- 
5 4 3 2

*/