class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class circularSinglyLinkedList:
    def __init__(self):
        self.last = None

    def insertFirst(self):
        data = int(input("Enter the value of the node to be inserted : "))
        newNode = Node(data)
        if (self.last == None):
            self.last = newNode
            newNode.next = self.last
        else:
            head = self.last.next
            self.last.next = newNode
            newNode.next = head

        print("The Node has been inserted in the beginning of the list\n")

    def deleteFirst(self):
        if (self.last == None):
            print("The list is empty\n")
        elif (self.last.next == self.last):
            print("Removed first : ", self.last.data, "\n")
            self.last = None
        else:
            head = self.last.next
            print("Removed first : ", head.data, "\n")
            head = head.next
            self.last.next = head

    def insertLast(self):
        data = int(input("Enter the value of the node to be inserted : "))
        newNode = Node(data)
        if (self.last == None):
            self.last = newNode
            newNode.next = self.last
        else:
            head = self.last.next
            self.last.next = newNode
            newNode.next = head
            self.last = newNode
        print("The Node has been inserted in the end of the list\n")

    def deleteLast(self):
        if (self.last == None):
            print("The list is empty\n")
        elif (self.last.next == self.last):
            print("Removed last : ", self.last.data, "\n")
            self.last = None
        else:
            print("Removed last : ", self.last.data, "\n")
            head = self.last.next
            curr = head
            while curr.next.next != head:
                curr = curr.next
            self.last = curr
            self.last.next = head

    def search(self, item):
        if (self.last == None):
            print("List is empty\n")
        else:
            head = self.last.next
            curr = head
            flag = 0
            while curr.next != head:
                if (curr.data == item):
                    flag = 1
                curr = curr.next

            if curr.data == item:
                flag = 1

            if (flag):
                print("item was found\n")
            else:
                print("not found\n")

    def display(self):
        if (self.last == None):
            print("List is empty\n")
        else:
            head = self.last.next
            curr = head
            print("the elements of the list are:")
            while curr.next != head:
                print(curr.data, end=" ")
                curr = curr.next
            print(curr.data, "\n")


CSLL = circularSinglyLinkedList()
while True:
    print("Enter a option you want to perform ")
    op = int(
        input("1.Insert First \n2.Delete First \n3.Insert Last \n4.Delete Last \n5.search \n6.display \n7.exit \n"))
    if (op == 1):
        CSLL.insertFirst()
    elif (op == 2):
        CSLL.deleteFirst()
    elif (op == 3):
        CSLL.insertLast()
    elif (op == 4):
        CSLL.deleteLast()
    elif (op == 5):
        item = int(input("enter the item to be searched : "))
        CSLL.search(item)
    elif (op == 6):
        CSLL.display()
    elif (op == 7):
        exit()
    else:
        print("enter correct option")

"""
Implementation of Circular_singly_Linked_List

Sample output:

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
1
Enter the value of the node to be inserted : 1
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
1
Enter the value of the node to be inserted : 2
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
1
Enter the value of the node to be inserted : 3
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
6
the elements of the list are:
3 2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
3
Enter the value of the node to be inserted : 5
The Node has been inserted in the end of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
6
the elements of the list are:
3 2 1 5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
2
Removed first :  3

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
6
the elements of the list are:
2 1 5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
4
Removed last :  5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
6
the elements of the list are:
2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
5
enter the item to be searched : 1
item was found

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
5
enter the item to be searched : 6
not found

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
2
Removed first :  2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
4
Removed last :  1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
2
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
4
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
6
List is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
5
enter the item to be searched : 2
List is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.display
7.exit
7

Time Complexity:
----------------------------------------------
Insert First   : O(1)
Delete First   : O(1)
Insert Last    : O(1)
Delete Last    : O(n)
Search         : O(n)

Space Complexity: 
-----------------------------------------------
Circular-singly-Linked-List : O(n)


"""