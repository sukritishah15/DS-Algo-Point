package Java.DataStructures;

import java.io.*;

/* JAVA program to print the middle element in a linked list.

For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element.
For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

we can implement the solution in one traversal,
The idea is to use two pointers:
1) the slow pointer that increment by 1 node at a time.
2) the fast pointer that increment by 2 nodes at a time.

so when fast pointer reaches the end of the linked list,
the slow pointer is at the middle of linked list.
as, 2 * middle = end.

*/
public class Middle_element_of_a_Linked_List { 
	
	public static class LinkedList{
		Node head; // head of list 
		
	}

	

	// Linked list Node. 
	// This inner class is made static 
	// so that main() can access it 
	static class Node { 

		int data; 
		Node next; 

		
		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 

	// Method to insert a new node 
	public static LinkedList insert(LinkedList list, int data) 
	{ 
		
		Node new_node = new Node(data); 
		new_node.next = null; 

		 
		if (list.head == null) { 
			list.head = new_node; 
		} 
		else { 
			
			Node last = list.head; 
			while (last.next != null) { 
				last = last.next; 
			} 

			
			last.next = new_node; 
		} 

		 
		return list; 
	} 

	// Method to print the middle element of the LinkedList. 
	public static void printMiddleElement(LinkedList list) 
	{ 
		Node slow_pointer = list.head;
        Node fast_pointer = list.head; 

		System.out.print("Middle element of the LinkedList is: "); 

		// Traverse through the LinkedList incrementing both pointers until the fast one
        // reaches the end
		while (fast_pointer != null && fast_pointer.next != null) { 
			slow_pointer = slow_pointer.next;//increment slow pointer by 1 node.
			          
            fast_pointer = fast_pointer.next.next; //increment fast pointer by 2 nodes.
            

		}

        // now the fast pointer must have reached the end and the slow pointer
        // must have reached the middle of linked list.
        // So we print the slow pointer.

         System.out.println(slow_pointer.data);
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		/* Create first empty linked list */
		LinkedList list1 = new LinkedList(); 

		// Insert the values 
		list1 = insert(list1, 1); 
		list1 = insert(list1, 2); 
		list1 = insert(list1, 3); 
		list1 = insert(list1, 4); 
		list1 = insert(list1, 5); 

		// Print the middle element of first LinkedList 
		printMiddleElement(list1); 

        /* Create second empty linked list */
        LinkedList list2 = new LinkedList();

        list2 = insert(list2, 1); 
		list2 = insert(list2, 2); 
		list2 = insert(list2, 3); 
		list2 = insert(list2, 4); 
		list2 = insert(list2, 5);
		list2 = insert(list2, 6);

        // Print the middle element of second LinkedList
        printMiddleElement(list2); 
	} 
} 


/* 
Time Complexity = O(n)
space Complexity = O(1)

Input:
*the two linked lists are given as input in the program itself.

Output:
Middle element of the LinkedList is: 3
Middle element of the LinkedList is: 4


 */

