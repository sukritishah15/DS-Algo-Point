class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class circularDoublyLinkedList:
    def __init__(self):
        self.last = None

    def insertFirst(self):
        data = int(input("Enter the value of the node to be inserted : "))
        newNode = Node(data)
        if (self.last == None):
            self.last = newNode
            newNode.next = self.last
            newNode.prev = self.last
        else:
            head = self.last.next
            self.last.next = newNode
            newNode.prev = self.last
            newNode.next = head
            head.prev = newNode

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
            head.prev = self.last
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
            newNode.prev = self.last
            newNode.next = head
            head.prev = newNode
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
            head.prev = self.last

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

    def displayForeward(self):
        if (self.last == None):
            print("List is empty\n")
        else:
            head = self.last.next
            curr = head
            print("the elements of the list in foreward direction are : ")
            while curr.next != head:
                print(curr.data, end=" ")
                curr = curr.next
            print(curr.data, "\n")

    def dislplayBackWard(self):
        if (self.last == None):
            print("List is Empty\n")
        else:
            head = self.last.next
            curr = head
            print("the elements of the list in backward direction are : ")
            while curr.next != head:
                curr = curr.next
            while curr != head:
                print(curr.data, end=" ")
                curr = curr.prev
            print(curr.data, "\n")


CDLL = circularDoublyLinkedList()
while True:
    print("Enter a option you want to perform ")
    op = int(input(
        "1.Insert First \n2.Delete First \n3.Insert Last \n4.Delete Last \n5.search \n6.displayForeward \n7.dislplayBackWard \n8.exit \n"))
    if (op == 1):
        CDLL.insertFirst()
    elif (op == 2):
        CDLL.deleteFirst()
    elif (op == 3):
        CDLL.insertLast()
    elif (op == 4):
        CDLL.deleteLast()
    elif (op == 5):
        item = int(input("enter the item to be searched : "))
        CDLL.search(item)
    elif (op == 6):
        CDLL.displayForeward()
    elif (op == 7):
        CDLL.dislplayBackWard()
    elif (op == 8):
        exit()
    else:
        print("enter correct option")

"""
Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
1
Enter the value of the node to be inserted : 1
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
1
Enter the value of the node to be inserted : 2
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
1
Enter the value of the node to be inserted : 3
The Node has been inserted in the beginning of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
7
the elements of the list in backward direction are :
1 2 3

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
6
the elements of the list in foreward direction are :
3 2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
3
Enter the value of the node to be inserted : 5
The Node has been inserted in the end of the list

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
6
the elements of the list in foreward direction are :
3 2 1 5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
2
Removed first :  3

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
4
Removed last :  5

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
6
the elements of the list in foreward direction are :
2 1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
7
the elements of the list in backward direction are :
1 2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
5
enter the item to be searched : 2
item was found

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
5
enter the item to be searched : 6
not found

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
2
Removed first :  2

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
2
Removed first :  1

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
2
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
4
The list is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
5
enter the item to be searched : 5
List is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
6
List is empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
7
List is Empty

Enter a option you want to perform
1.Insert First
2.Delete First
3.Insert Last
4.Delete Last
5.search
6.displayForeward
7.dislplayBackWard
8.exit
8

Time Complexity:
----------------------------------------------
Insert First   : O(1)
Delete First   : O(1)
Insert Last    : O(1)
Delete Last    : O(n)
Search         : O(n)

Space Complexity: 
-----------------------------------------------
Circular-Doubly-Linked-List : O(n)

"""