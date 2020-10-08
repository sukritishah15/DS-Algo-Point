class DataStructures.Algorithms.DataStructures.Node:
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
root = DataStructures.Algorithms.DataStructures.Node(1)
root.left      = DataStructures.Algorithms.DataStructures.Node(2)
root.right     = DataStructures.Algorithms.DataStructures.Node(3)
root.left.left  = DataStructures.Algorithms.DataStructures.Node(4)
root.left.right  = DataStructures.Algorithms.DataStructures.Node(5)
print "Preorder traversal of binary tree is"
printPreorder(root) 
  '''
  
  
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Prerder traversal of binary tree is
          1 2 4 5 3
  
  '''
