package Java.DataStructures;

import java.util.*;

// Class for queue
class Queue
{
	private int arr[];		// array to store queue elements
	private int front;		// front points to front element in the queue (if any)
	private int rear;		// rear points to last element in the queue
	private int capacity;	// maximum capacity of the queue
	private int count;		// current size of the queue

	// Constructor to initialize queue
	Queue(int size)
	{
		arr = new int[size];
		capacity = size;
		front = 0;
		rear = -1;
		count = 0;
	}

	// Utility function to remove front element from the queue
	public void dequeue()
	{
		// check for queue underflow
		if (isEmpty())
		{
			System.out.println("UnderFlow\nProgram Terminated");
			System.exit(1);
		}

		System.out.println("Removing " + arr[front]);

		front = (front + 1) % capacity;
		count--;
	}

	// Utility function to add an item to the queue
	public void enqueue(int item)
	{
		// check for queue overflow
		if (isFull())
		{
			System.out.println("OverFlow\nProgram Terminated");
			System.exit(1);
		}

		System.out.println("Inserting " + item);

		rear = (rear + 1) % capacity;
		arr[rear] = item;
		count++;
	}

	// Utility function to return front element in the queue
	public int peek()
	{
		if (isEmpty())
		{
			System.out.println("UnderFlow\nProgram Terminated");
			System.exit(1);
		}
		return arr[front];
	}

	// Utility function to return the size of the queue
	public int size()
	{
		return count;
	}

	// Utility function to check if the queue is empty or not
	public Boolean isEmpty()
	{
		return (size() == 0);
	}

	// Utility function to check if the queue is full or not
	public Boolean isFull()
	{
		return (size() == capacity);
	}
}

class Main
{
		public static void main (String[] args)
	{
		// create a queue of capacity 5
		Queue q = new Queue(5);

		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);

		System.out.println("Front element is: " + q.peek());
		q.dequeue();
		System.out.println("Front element is: " + q.peek());

		System.out.println("Queue size is " + q.size());

		q.dequeue();
		q.dequeue();

		if (q.isEmpty())
			System.out.println("Queue Is Empty");
		else
			System.out.println("Queue Is Not Empty");
	}
}



/**
 * 

Sample output
Inserting 1
Inserting 2
Inserting 3
Front element is: 1
Removing 1
Front element is: 2
Queue size is 2
Removing 2
Removing 3
Queue Is Empty

time complexity :
	search:0(n)
	access:0(n)
	insertion:0(1)
	deletion:0(1)
Space complexity:O(n)
 */