class Queue:
    def __init__(self,ms):
        self.myqueue=[]
        self.maxsize=ms
        self.front=0
        self.rear=0
    def EnQueue(self):
        
        if len(self.myqueue)==self.maxsize:
            print("Queue is full . no new element can be added")
        else:
            data=int(input("Enter data to enqueue  "))
            self.myqueue.append(data)
            self.rear=(self.rear+1)%self.maxsize
            print("Data added to queue")
    def DeQueue(self):
        if len(self.myqueue)==0:
            print("DeQueue cannot be performed  ")
        else:
            
            print("Removed",self.myqueue.pop(self.front))
            self.front=(self.front+1)%self.maxsize
            
            if self.front>=self.rear:
                self.front=0
        
    def isEmpty(self):
        if len(self.myqueue)==0:
            print("Queue is empty")
        else:
            print("Queue is not empty")
    def display(self):
        print("Elements in Queue are")
        print(self.myqueue)
    def peek(self):
        print("The first element in the Queue is ",self.myqueue[self.front])
        
    def length(self):
        print("Length of CircularQueue is ",len(self.myqueue))


ms=int(input("Enter maximum size for cricular queue \n"))
Q=Queue(ms)
while True:
    print("Enter a option you want to perform ")
    op=int(input("\n1.enque \n2.dequeue \n3.display \n4.peek \n5.isEmpty \n6.length \n7.Exit \n"))
    if(op==1):
        
        Q.EnQueue()
    elif(op==2):
        Q.DeQueue()
    elif(op==3):
        Q.display()
    elif(op==4):
        Q.peek()
    elif(op==5):
        Q.isEmpty()
    elif(op==6):
        Q.length()
    elif(op==7):
        exit()
    else:
        print("enter correct option")


"""
Implementation of Circular Queue

Sample output:
Enter maximum size for cricular queue 
3
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
1
Enter data to enqueue  1
Data added to queue
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
1
Enter data to enqueue  2
Data added to queue
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
1
Enter data to enqueue  3
Data added to queue
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
3
Elements in Queue are
[1, 2, 3]
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
4
The first element in the Queue is  1
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
5
Queue is not empty
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
6
Length of CircularQueue is  3
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
2
Removed 1
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
2
Removed 2
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
2
Removed 3
Enter a option you want to perform 

1.enque 
2.dequeue 
3.display 
4.peek 
5.isEmpty 
6.length 
7.Exit 
7



"""
