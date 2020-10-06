#include <iostream>

using namespace std;

// Node for linked list
struct Node 
{
	int data; 
	struct Node* next;

    // Constructor
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

// LinkedList
struct LinkedList 
{
    // Head pointer
	Node* head;

    // Constructor
	LinkedList()
	{ 
		head = NULL;
	}

	// Reversing the given linked list
	void reverse()
	{
        // Initialize the current pointer to head
		Node* current = head;
		Node *prev = NULL, *next = NULL;

        // Iterate till the current pints to NULL
		while (current != NULL) {
			// Store the next node separately
			next = current->next;

			// Reverse current node's pointer
			current->next = prev;

            // Change the prev pointer to value of current pointer
            // for the next iteration
			prev = current;

            // Change the current pointer to the next pointer
			current = next;
		}
        // Change the head pointer to last node
		head = prev;
	}

	// Printing the linked list
	void display()
	{
        // Initialize tmp pointer to head
		struct Node* current = head;

        // Iterate till the reach the last node
		while (current != NULL) {
			cout << current->data << "->";
            // Move to next node
			current = current->next;
		}
        cout << "NULL" << endl;
	}
};

int main()
{
    // Declaring a empty list
	LinkedList ll;

    // Declaring and initializing current pointer to head
    Node *current = ll.head;

    // Creating a linked list
    for (int i = 1; i <= 6; i++)
    {
        // Creating a new node
        Node* newNode = new Node(i);

        // If current/head is NULL, make head point to newNode
        if (current == NULL)
        {
            ll.head = newNode;
            current = ll.head;
        }
        else
        {
            // Make current point to newNode
            current->next = newNode;
            // Move the current pointer to next node in the list
            current = current->next;
        }
    }
	
    // Displaying the linked list
	cout << "Linked List: ";
	ll.display();

    // Reversing the linked list
	ll.reverse();

    // Displaying the reversed linked list
	cout << "\nReversed Linked List: ";
	ll.display();

	return 0; 
} 

/*
Input: Hard-coded, which was given in the issue

Output:
Linked List: 1->2->3->4->5->6->NULL

Reversed Linked List: 6->5->4->3->2->1->NULL

Time complexity: O(n)

Space complexity: O(1)
*/
