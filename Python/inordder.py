class DataStructures.Algorithms.DataStructures.Node:
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
        
def printInorder(root): 

    if root: 
        printInorder(root.left) 
        print(root.val), 
        printInorder(root.right) 

root = DataStructures.Algorithms.DataStructures.Node(1)
root.left      = DataStructures.Algorithms.DataStructures.Node(2)
root.right     = DataStructures.Algorithms.DataStructures.Node(3)
root.left.left  = DataStructures.Algorithms.DataStructures.Node(4)
root.left.right  = DataStructures.Algorithms.DataStructures.Node(5)

print "\nInorder traversal of binary tree is"
printInorder(root) 

'''
  Time Complexity - O(N)
  Space Complexity - O(N)

  Input - Taken in the Code .
  Output -Inorder traversal of binary tree is
          4 2 5 1 3 
'''
