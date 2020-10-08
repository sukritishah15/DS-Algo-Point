class DataStructures.Queue:
    def __init__(self, mx_size):
        self.myQueue = []
        self.maxSize = mx_size
        self.front = -1
        self.rear = -1

    def EnQueue(self):
        if self.front != -1 and (self.rear - self.front + 1) == self.maxSize:
            print("DataStructures.Queue is full . no new element can be added \n")
        else:
            data = int(input("Enter data to enqueue : "))
            if (self.front == -1):
                self.front = 0
            self.rear += 1
            self.myQueue.append(data)
            print("Data added to queue \n")

    def DeQueue(self):
        if (self.front > self.rear or self.front == -1):
            print("DeQueue can not be performed \n")
        else:
            print("Removed : ", self.myQueue[self.front], "\n")
            self.front += 1

    def isEmpty(self):
        if (self.front > self.rear or self.front == -1):
            print("DataStructures.Queue is Empty\n")
        else:
            print("DataStructures.Queue is not empty\n")

    def display(self):
        if (self.front > self.rear or self.front == -1):
            print("DataStructures.Queue is Empty\n")
        else:
            print("The elements in the queue are : ")
            for i in range(self.front, self.rear + 1):
                print(self.myQueue[i], end=" ")
            print("\n")

    def peekFront(self):
        if (self.front > self.rear or self.front == -1):
            print("DataStructures.Queue is Empty\n")
        else:
            print("The first element in the DataStructures.Queue is : ", self.myQueue[self.front], "\n")

    def peekRear(self):
        if (self.front > self.rear or self.front == -1):
            print("DataStructures.Queue is Empty\n")
        else:
            print("The last element in the DataStructures.Queue is : ", self.myQueue[self.rear], "\n")

    def length(self):
        if (self.front == -1):
            size = 0
        else:
            size = self.rear - self.front + 1
        print("Length of the DataStructures.Queue is ", size, "\n")


ms = int(input("Enter the maximum size for the queue : "))
Q = DataStructures.Queue(ms)

while True:
    print("Enter a option you want to perform ")
    op = int(input("1.enqueue \n2.dequeue \n3.display \n4.peekFront \n5.peekRear \n6.isEmpty \n7.length \n8.Exit \n"))
    ls = [Q.EnQueue, Q.DeQueue, Q.display, Q.peekFront, Q.peekRear, Q.isEmpty, Q.length]
    
    if op<=8 and op>=1:
        ls[op-1]()
    else:
        print("enter correct option")
	
"""
Implementation of DataStructures.Queue

Sample output:

Enter the maximum size for the queue : 3
Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 1
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 2
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 3
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
3
The elements in the queue are :
1 2 3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
4
The first element in the DataStructures.Queue is :  1

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
5
The last element in the DataStructures.Queue is :  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
6
DataStructures.Queue is not empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
7
Length of the DataStructures.Queue is  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
2
Removed :  1

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
2
Removed :  2

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
3
The elements in the queue are :
3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
4
The first element in the DataStructures.Queue is :  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
5
The last element in the DataStructures.Queue is :  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
6
DataStructures.Queue is not empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
7
Length of the DataStructures.Queue is  1

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
2
Removed :  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
2
DeQueue can not be performed

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
3
DataStructures.Queue is Empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
4
DataStructures.Queue is Empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
5
DataStructures.Queue is Empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
6
DataStructures.Queue is Empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
7
Length of the DataStructures.Queue is  0

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 4
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 5
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
1
Enter data to enqueue : 6
Data added to queue

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
3
The elements in the queue are :
4 5 6

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
4
The first element in the DataStructures.Queue is :  4

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
5
The last element in the DataStructures.Queue is :  6

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
6
DataStructures.Queue is not empty

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
7
Length of the DataStructures.Queue is  3

Enter a option you want to perform
1.enqueue
2.dequeue
3.display
4.peekFront
5.peekRear
6.isEmpty
7.length
8.Exit
8

Time Complexity:
----------------------------------------------
Enqueue   : O(1)
Dequeue   : O(1)
peekRear  : O(1)
peekFront : O(1)

Space Complexity: 
-----------------------------------------------
DataStructures.Queue : O(n)



"""
