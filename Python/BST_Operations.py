#Basic Operations in a Binary Search Tree(BST) in Python

#Creating a class to create a node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# Inserting a node
def insert(node, key):

    # Return a new node if the tree is empty
    if node is None:
        return Node(key)

    # Traverse to the right place and insert the node
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node


# Deleting a node
def deleteNode(root, key):

    # Return if the tree is empty
    if root is None:
        return root

    # Find the node to be deleted
    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif(key > root.key):
        root.right = deleteNode(root.right, key)
    else:
        # If the node is with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # If the node has two children,
        # place the inorder successor in position of the node to be deleted
        temp = minValueNode(root.right)

        root.key = temp.key

        # Delete the inorder successor
        root.right = deleteNode(root.right, temp.key)

    return root

print("\nInsert nodes in the Binary Search Tree")
#To implement the Operations
root_node = None
root_node = insert(root_node, 10)
root_node = insert(root_node, 4)
root_node = insert(root_node, 3)
root_node = insert(root_node, 12)
root_node = insert(root_node, 6)
root_node = insert(root_node, 11)
root_node = insert(root_node, 14)
root_node = insert(root_node, 8)

print("\nDelete 10")
root = deleteNode(root, 10)
