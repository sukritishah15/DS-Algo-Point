class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

class doublyLinkedList:
	def __init__(self):
		self.head = None
	def insertFirst(self):
		data = int(input("Enter the value of the node to be inserted : "))
		newNode = Node(data)

		newNode.next = self.head
		newNode.prev = None

		if self.head != None:
			self.head.prev = newNode

		self.head = newNode
		print("New node has been inserted into the beginning doubly linked list \n")

	def deleteFirst(self):
		if self.head == None:
			print("The list is empty\n")
		elif self.head.next == None:
			print("Removed the first node : ", self.head.data, "\n")
			self.head = None
		else:
			print("Removed the first node : ", self.head.data, "\n")
			self.head = self.head.next
			self.head.prev = None

	def insertLast(self):
		data = int(input("Enter the vlaue of the node to be inserted : "))
		newNode = Node(data)

		if self.head is None:
			self.head = newNode
		else:
			curr = self.head
			while curr.next != None:
				curr = curr.next

			curr.next = newNode
			newNode.prev = curr
		print("New node has been inserted into the end doubly linked list \n")

	def deleteLast(self):
		if self.head == None:
			print("The list is empty\n")
		elif self.head.next == None:
			print("Removed the last node : ", self.head.data, "\n")
			self.head = None
		else:
			curr = self.head
			while curr.next != None:
				curr = curr.next
			print("Removed the last node : ", curr.data, "\n")
			curr = curr.prev
			curr.next = None


	def insertAfter(self, prev_node):
		data = int(input("Enter the value of the node to be inserted : "))
		if prev_node == None:
			print("Previous node can not be Null")
		else:
			newNode = Node(data)
			nxt_node = prev_node.next
			newNode.prev = prev_node
			prev_node.next = newNode
			newNode.next = nxt_node
			nxt_node.prev = newNode
		print("The Node has been sucessfully inserted after ", prev_node.data, "\n")

	def delete(self):
		key = int(input("Enter the key to be deleted : "))
		flag = 0
		curr = self.head
		while curr != None:
			if(curr.data == key):
				flag = 1
				break
			curr = curr.next
		if flag:
			prev_node = curr.prev
			nxt_node = curr.next
			prev_node.next = nxt_node
			nxt_node.prev = prev_node
			print(key, "was deleted\n")
		else:
			print("The key was not found\n")

	def displayForeward(self):
		if(self.head == None):
			print("The list is empty\n")
		else:
			print("The elements of the DLL in foreward direction")
			curr = self.head
			while curr != None:
				print(curr.data, end = " ")
				curr = curr.next
		print()

	def displayBackward(self):
		if(self.head == None):
			print("The list is empty\n")
		else:
			print("The elements of the DLL in backward direction")
			curr = self.head
			while curr.next != None:
				curr = curr.next
			while curr != None:
				print(curr.data, end = " ")
				curr = curr.prev
			print()

DLL = doublyLinkedList()
while True:
	print("Enter a option you want to perform ")
	op=int(input("1.Insert First \n2.Delete First \n3.Insert Last \n4.Delete Last \n5.Insert After \n6.Delete \n7.Display Foreward \n8.Display Backward \n9.Exit \n"))
	if(op==1):
		DLL.insertFirst()
	elif(op==2):
		DLL.deleteFirst()
	elif(op==3):
		DLL.insertLast()
	elif(op==4):
		DLL.deleteLast()
	elif(op==5):

		x = int(input("enter the  value of the node After which you want to insert the new node : "))
		curr = DLL.head
		flag = 0
		while curr != None:
			if(curr.data == x):
				flag = 1
				break
			curr = curr.next
		if(flag):
			DLL.insertAfter(curr)
		else:
			print("The Node was not found")

	elif(op==6):
		DLL.delete()
	elif(op == 7):
		DLL.displayForeward()
	elif(op==8):
		DLL.displayBackward()
	elif(op == 9):
		exit()
	else:
		print("enter correct option")


"""
Implementation of DoublyLinkedList

Sample output:

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
1
Enter the value of the node to be inserted : 1
New node has been inserted into the beginning doubly linked list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
1
Enter the value of the node to be inserted : 2
New node has been inserted into the beginning doubly linked list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
1
Enter the value of the node to be inserted : 3
New node has been inserted into the beginning doubly linked list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
3 2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
3
Enter the vlaue of the node to be inserted : 5
New node has been inserted into the end doubly linked list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
3 2 1 5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
8
The elements of the DLL in backward direction
5 1 2 3

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
2
Removed the first node :  3

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
2 1 5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
4
Removed the last node :  5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
5
enter the  value of the node After which you want to insert the new node : 2
Enter the value of the node to be inserted : 13
The Node has been sucessfully inserted after  2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
2 13 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
6
Enter the key to be deleted : 13
13 was deleted

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The elements of the DLL in foreward direction
2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
8
The elements of the DLL in backward direction
1 2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
2
Removed the first node :  2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
4
Removed the last node :  1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
2
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
4
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
7
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
8
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.Insert After
6.Delete
7.Display Foreward
8.Display Backward
9.Exit
9

Time Complexity:
----------------------------------------------
Insert First   : O(1)
Delete First   : O(1)
Insert Last    : O(n)
Delete Last    : O(n)
Delete After   : O(n)
delete         : O(n)

Space Complexity: 
-----------------------------------------------
Doubly-Linked-List : O(n)


"""