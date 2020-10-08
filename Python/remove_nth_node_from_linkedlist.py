class DataStructures.Algorithms.DataStructures.Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class DataStructures.LinkedList:
    def __init__(self):
        self.size=1
        self.head=None
        self.tail=None
    def append(self,node):
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
        self.size+=1
    def display(self):
        self.current=self.head
        print(self.head.data)
        while(self.current.next!=None):
        #until a node is found with next property as null
            #overwriting current node as next node
            self.previous=self.current
            self.current=self.current.next
            print(self.current.data)
    def DeleteNthNode(self,n):
        if(self.size<=n):
            print('size too small')
            return
        if(n==0):
            self.head=self.head.next
            #replace head
            return
        counter=0
        self.current=self.head
        while(self.current.next!=None):
        #until a node is found with next property as null
            #overwriting current node as next node
            self.previous=self.current
            self.current=self.current.next
            counter+=1            
            if(counter==n):
                #if we reach the element we want to delete
                if(self.current.next==None):
                    #if current element is tail
                    self.previous.next=None
                    #resetting tail
                    self.tail=self.previous
                else:
                    #previous elements link is overwritten with next to next node
                    self.previous.next=self.current.next
                break
                
        
op=1
linkedlist=DataStructures.LinkedList()
while(op):
    print("0. exit")
    print("1. append data to linkedlist")
    print("2. display linkedlist")
    print("3. remove nth node")
    op=int(input('enter the operation you want to perform '))
    if(op==1):
        data=int(input('enter value of node '))
        linkedlist.append(DataStructures.Algorithms.DataStructures.Node(data))
    elif(op==2):
        linkedlist.display()
    elif (op==3):
        n=int(input('enter the number of node you want to delete'))
        linkedlist.DeleteNthNode(n-1)
        print("new linked list")
        linkedlist.display()


"""
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 1
enter value of node 10
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 1
enter value of node 20
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 1
enter value of node 30
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 1
enter value of node 40
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 1
enter value of node 50
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 3
enter the number of node you want to delete1
new linked list
20
30
40
50
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 3
enter the number of node you want to delete2
new linked list
20
40
50
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 3
enter the number of node you want to delete3
new linked list
20
40
0. exit
1. append data to linkedlist
2. display linkedlist
3. remove nth node
enter the operation you want to perform 0

    SPACE COMPLEXITY:O(n)
    TIME COMPLEXITY:O(1)
"""
