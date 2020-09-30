#implementation of stack using OOP
#stack is used to store and retrive data
# the process for stack is FILO i.e.first in last out
class stack:
    def __init__(self):
        #constructor for stack
        self.mylist=[]
        self.size=0
        self.maxsize=5

    #function to display elements of stack
    def display(self):
        print(self.mylist)

    #function to display length of stack
    def length(self):
        print(self.size)
    #function to add element to stack
    def push(self,data):
        if (self.size==self.maxsize):
            print('stack is full ,stack overflow')
            return None
        self.mylist.append(data)
        self.size+=1
        print("Data added to stack.")
    #function to remove elements from stack
    def pop(self):
        if(self.size==0):
            print("Stack is empty..no data can be popped ")
        else:
            self.mylist.pop()
            self.size-=1
            print("Data removed from stack.")

    #function to display element on top of stack
    def peek(self):
        if(self.size==0):
            print("Stack is empty...therefore no peek")
        else:
            print("Topmost element in the stack is: ",self.mylist[self.size-1])
    #function to check if stack is empty
    def isEmpty(self):
        if(self.size==0):
            print("Stack is empty")
        else:
            print("stack is not empty")

s1=stack()

print("Enter option that you want to perform")
op=int(input("1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : "))

while(op<=6):
    if(op==1):
        data=int(input("Enter data to add: "))
        s1.push(data)
        
    elif(op==2):
        s1.pop()
        
    elif(op==3):
        s1.display()
        
    elif(op==4):
        s1.peek()
        
    elif(op==5):
        s1.length()
        
    elif(op==6):
        s1.isEmpty()
        
    else:
        print("Invalid option.")

    print("Enter option that you want to perform")
    op=int(input("1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : "))
    print()


"""
I/O
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 23
Data added to stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 55
Data added to stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 10
Data added to stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 30
Data added to stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 29
Data added to stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 1
Enter data to add: 3
stack is full ,stack overflow
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 3
[23, 55, 10, 30, 29]
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 2
Data removed from stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 4
Topmost element in the stack is:  30
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 3
[23, 55, 10, 30]
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 6
stack is not empty
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 2
Data removed from stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 2
Data removed from stack.
Enter option that you want to perform
1:push 2:pop 3:display 4:peek 5:length 6:isEmpty : 2
SPACE COMPLEXITY:O(n)
TIME COMPLEXITY:O(1)
"""