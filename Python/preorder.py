class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
  
   
# A function to do preorder tree traversal 
def printPreorder(root): 
  
    if root: 
  
        # First print the data of node 
        print(root.val), 
  
        # Then recur on left child 
        printPreorder(root.left) 
  
        # Finally recur on right child 
        printPreorder(root.right) 
  
  
# Driver code 
root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 
print "Preorder traversal of binary tree is"
printPreorder(root) 
  /*
  
  
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Prerder traversal of binary tree is
          1 2 4 5 3
  
  */
