import math
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:
    def __init__(self):
        self.size=0
        self.head=None
        self.tail=None
    def append(self,node):
        self.size+=1
        if(self.head==None):
            self.head=node
            return None
        self.current=self.head
        while(self.current.next!=None):
        #until a node is found with next property as null
            #overwriting current node as next node
            self.previous=self.current
            self.current=self.current.next
        #now current node is tail node
        #adding new node to tail and incrementing tail
        self.current.next=node
        self.tail=self.current.next
        
    def display(self):
        self.current=self.head
        print(self.head.data)
        while(self.current.next!=None):
        #until a node is found with next property as null
            #overwriting current node as next node
            self.previous=self.current
            self.current=self.current.next
            print(self.current.data)
    def FindMidElement(self):
        #setting a counter
        if(self.size<3):
            print('size too low to find mid element')
            print('please add more items')
            return
        counter=math.floor(self.size/2)
        self.current=self.head
        while(self.current.next!=None):
        #until a node is found with next property as null
            if(counter==0):
                print('mid element found')
                print(self.current.data)
                break
            #overwriting current node as next node
            self.previous=self.current
            self.current=self.current.next
            counter-=1

op=1
linkedlist=LinkedList()
while(op):
    print("0. exit")
    print("1. append data to linkedlist")
    print("2. display linkedlist")
    print("3. display mid element")

    op=int(input('enter the operation you want to perform '))
    if(op==1):
        data=int(input('enter value of node '))
        linkedlist.append(Node(data))
    elif(op==2):
        linkedlist.display()
    elif(op==3):
        linkedlist.FindMidElement()
'''
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 1
    enter value of node 10
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 1
    enter value of node 20
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 1
    enter value of node 30
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 3
    mid element found
    20
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 1
    enter value of node 40
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 3
    mid element found
    30
    0. exit
    1. append data to linkedlist
    2. display linkedlist
    3. display mid element
    enter the operation you want to perform 0
    SPACE COMPLEXITY:O(n)
    TIME COMPLEXITY:O(1)
'''
