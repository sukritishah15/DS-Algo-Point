package Java.DataStructures;//Rotate Linked List in K Groups (Issue #65)
//https://github.com/sukritishah15/DS-Algo-Point/issues/65
//Contributed by @mephi007 : https://github.com/mephi007

import java.util.Scanner;

class Node{
	int val;
	Node next;
	public Node(int val) {
		this.val = val;
		this.next = null;
	}
}

public class RotateLinkedListKGroups {
	static Node head;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Enter number of elements to be in List");
		Scanner sc = new Scanner(System.in);
		int n= sc.nextInt();
		System.out.println("Enter elements in linked list");
		for(int i = 0; i<n; i++) {
			int ele = sc.nextInt();
			insertToLL(ele);
		}
		System.out.println("Linked List before rotation");
		printLL(head);
		System.out.println("Enter the group size");
		int k = sc.nextInt();
		System.out.println("Linked List after rotation");
		head = reverseKnodes(head, k);
		printLL(head);
	}
	private static Node reverseKnodes(Node head, int k) {
		// TODO Auto-generated method stub
		Node prev = null;
		Node next = null;
		Node curr = head;
	        
	        //to check is left over list do not have nodes upto k
		Node temp = head;
	        for(int i=1; i<k && temp != null; i++){
	            temp = temp.next;
	        }
	        
	        //if so return head, coz no reverse operation has to take place
	        if(temp == null){
	            return head;
	        }
	        
	        int count =0;
	        while(count < k && curr != null){
	            next = curr.next;
	            curr.next = prev;
	            prev = curr;
	            curr = next;
	            count++;
	        }
	        
	        if(next != null)
	            head.next = reverseKnodes(next,k);
	        
	        return prev;
	}
	private static void printLL(Node head) {
		// TODO Auto-generated method stub
		Node temp = head;
		while(temp != null) {
			System.out.print(temp.val+" ");
			temp = temp.next;
		}
		System.out.println();
	}
	private static void insertToLL(int ele) {
		// TODO Auto-generated method stub
		Node new_node = new Node(ele);
		if(head == null) {
			head = new_node;
			return;
		}
		new_node.next = head;
		head = new_node;
		
	}

}
/*
---Input and Ouput---
Enter number of elements to be in List
5
Enter elements in linked list
5
4
32
1
7
Linked List before rotation
7 1 32 4 5 
Enter the group size
3
Linked List after rotation
32 1 7 4 5 
--Time Complexity--
O(n)
--Space Complexity--
O(1)
*/