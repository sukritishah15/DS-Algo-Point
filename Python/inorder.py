class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
  
  
# A function to do inorder tree traversal 
def printInorder(root): 
  
    if root: 
  
        # First recur on left child 
        printInorder(root.left) 
  
        # then print the data of node 
        print(root.val), 
  
        # now recur on right child 
        printInorder(root.right) 
  
  
# Driver code 
root = Node(1) 
root.left      = Node(2) 
root.right     = Node(3) 
root.left.left  = Node(4) 
root.left.right  = Node(5) 
  
print "\nInorder traversal of binary tree is"
printInorder(root) 

/*
  Time Complexity - O(N)
  Space Complexity - O(N)
  
  Input - Taken in the Code .
  Output -Inorder traversal of binary tree is
          4 2 5 1 3 
*/
