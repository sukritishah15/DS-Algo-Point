# A Binary Tree Node 
class Node:

    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# A utility function to do inorder traversal of BST 
def inorder(root):
    if root is not None:
        inorder(root.left)
        print(root.key)
        inorder(root.right)


# A utility function to insert a new node with given key in BST
def insert(node, key):
    # If the tree is empty, return a new node
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    return node


# return the node with minimum key value found in that tree.
def minValueNode(node):
    current = node
    while current.left is not None:
        current = current.left

    return current


# this function deletes the key and returns the new root
def deleteNode(root, key):
    # Base Case
    if root is None:
        return root

    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif key > root.key:
        root.right = deleteNode(root.right, key)
    else:

        # Node with only one child or no child 
        if root.left is None:
            temp = root.right
            root = None
            return temp
        elif root.right is None:
            temp = root.left
            root = None
            return temp

        temp = minValueNode(root.right)
        root.key = temp.key
        root.right = deleteNode(root.right, temp.key)

    return root


# Driver program to test above functions
""" Let us create following BST 
              50 
           /      \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 """

root = None
root = insert(root, 50)
root = insert(root, 30)
root = insert(root, 20)
root = insert(root, 40)
root = insert(root, 70)
root = insert(root, 60)
root = insert(root, 80)

# Inorder traversal of the given tree"
inorder(root)

# Delete 20
root = deleteNode(root, 20)

# Inorder traversal of the modified tree
inorder(root)

# Delete 30
root = deleteNode(root, 30)

# Inorder traversal of the modified tree.
inorder(root)

# Delete 50
root = deleteNode(root, 50)

# Inorder traversal of the modified tree
inorder(root)

# output
'''
20
30
40
50
60
70
80
30
40
50
60
70
80
40
50
60
70
80
40
60
70
80
'''

'''
Time complexity: 
    Insertion: O(h) -> h = height of BST
    Deletion: O(h) -> h = height of BST
    Searching: O(h) -> h = height of BST
Space complexity: O(n) -> n = number of nodes
'''
