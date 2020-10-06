class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
  

def printPostorder(root): 
  
    if root: 
        printPostorder(root.left) 
        printPostorder(root.right) 
        print(root.val)


root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 

print("\nPostorder traversal of binary tree is")
printPostorder(root) 

"""
Time Complexity: O(N)
Space Complexity: If we don’t consider size of stack for function calls then O(1) otherwise O(N).
Input And Output:
Taken in The code.
4 5 2 3 1
"""