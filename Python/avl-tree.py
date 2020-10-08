#!/usr/bin/env python
# coding: utf-8

# In[2]:


class DataStructures.TreeNode(object):
    def __init__(self, val): 
        self.val = val 
        self.left = None
        self.right = None
        self.height = 1

class AVL_Tree(object): 
    def insert(self, root, key): 
        if not root: 
            return DataStructures.TreeNode(key)
        elif key < root.val: 
            root.left = self.insert(root.left, key) 
        else: 
            root.right = self.insert(root.right, key) 
        root.height = 1 + max(self.getHeight(root.left), 
                        self.getHeight(root.right)) 
        balance = self.getBalance(root) 
        if balance > 1 and key < root.left.val: 
            return self.rightRotate(root) 
        if balance < -1 and key > root.right.val: 
            return self.leftRotate(root) 
        if balance > 1 and key > root.left.val: 
            root.left = self.leftRotate(root.left) 
            return self.rightRotate(root) 
        if balance < -1 and key < root.right.val: 
            root.right = self.rightRotate(root.right) 
            return self.leftRotate(root) 
        return root 

    def delete(self, root, key): 
  
        if not root: 
            return root 
        elif key < root.val: 
            root.left = self.delete(root.left, key) 
        elif key > root.val: 
            root.right = self.delete(root.right, key) 
        else: 
            if root.left is None: 
                temp = root.right 
                root = None
                return temp 
            elif root.right is None: 
                temp = root.left 
                root = None
                return temp 
            temp = self.getMinValueNode(root.right) 
            root.val = temp.val 
            root.right = self.delete(root.right, 
                                      temp.val) 
        if root is None: 
            return root 
        root.height = 1 + max(self.getHeight(root.left), 
                            self.getHeight(root.right)) 
        balance = self.getBalance(root) 
        if balance > 1 and self.getBalance(root.left) >= 0: 
            return self.rightRotate(root) 
        if balance < -1 and self.getBalance(root.right) <= 0: 
            return self.leftRotate(root) 
        if balance > 1 and self.getBalance(root.left) < 0: 
            root.left = self.leftRotate(root.left) 
            return self.rightRotate(root) 
        if balance < -1 and self.getBalance(root.right) > 0: 
            root.right = self.rightRotate(root.right) 
            return self.leftRotate(root) 
        return root 
    
    def leftRotate(self, z): 
        y = z.right 
        T2 = y.left 
        y.left = z 
        z.right = T2 
        z.height = 1 + max(self.getHeight(z.left), 
                        self.getHeight(z.right)) 
        y.height = 1 + max(self.getHeight(y.left), 
                        self.getHeight(y.right)) 
        return y 

    def rightRotate(self, z): 
        y = z.left 
        T3 = y.right 
        y.right = z 
        z.left = T3 
        z.height = 1 + max(self.getHeight(z.left), 
                        self.getHeight(z.right)) 
        y.height = 1 + max(self.getHeight(y.left), 
                        self.getHeight(y.right)) 
        return y 

    def getHeight(self, root): 
        if not root: 
            return 0
        return root.height 

    def getBalance(self, root): 
        if not root: 
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right) 
    
    def getMinValueNode(self, root): 
        if root is None or root.left is None: 
            return root 
        return self.getMinValueNode(root.left) 

    def preOrder(self, root): 
        if not root: 
            return
        print("{0} ".format(root.val), end="") 
        self.preOrder(root.left) 
        self.preOrder(root.right) 

myTree = AVL_Tree() 
root = None

nums=list(map(int,input().split()))

for num in nums:
    root = myTree.insert(root, num) 

print("Preorder Traversal after insertion -") 
myTree.preOrder(root) 
print() 

key = int(input())
root = myTree.delete(root, key) 

print("Preorder Traversal after deletion -") 
myTree.preOrder(root) 
print() 

'''
Input:
10 20 30 40 50 25

Output:
Preorder Traversal after insertion -
30 20 10 25 40 50 
10
Preorder Traversal after deletion -
30 20 25 40 50 
'''

'''
Time complexity: O(log n)
Space complexity: O(n)
'''


# In[ ]:




