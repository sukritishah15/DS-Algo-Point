class node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

class tree:

    def inorder(self,root):

        if(root):
            self.inorder(root.left)

            if(root.data!=None):
                print(root.data,end=" ")

            self.inorder(root.right)

        else:
            return None
        
    
    
    def searching(self,root,val):
        
        ## using inorder traversal
        if root:
            
            res1=self.searching(root.left,val)
            if(res1):
                return True
            if(root.data==val):
                
                return True
            

            res2=self.searching(root.right,val)
            if(res2):
                return True

        else:
            return None

    
    def height(self,root):
    
        if(root):
            depth_left=self.height(root.left)
 
            depth_right=self.height(root.right)

            return (max(depth_right,depth_left)+1)
        else:
            return 0

    def diameter(self,root):

        if(root):

           ##diameter of root node of current subtree
           ##depth_left+depth_right

           depth_left=self.height(root.left)
           depth_right=self.height(root.right)

           diameter_left=self.diameter(root.left)
           diameter_right=self.diameter(root.right)

           return max((depth_left+depth_right+1),diameter_left,diameter_right)
        else:
            return 0

    def mirror(self,root):

        if(root):

            self.mirror(root.left)
            self.mirror(root.right)

            ##swapping

            temp=root.left
            root.left=root.right
            root.right=temp

        else:
            return None

    def height_balance(self,root):

        if(root):

            depth_left=self.height(root.left)

            depth_right=self.height(root.right)

            lbalance=self.height_balance(root.left)
            rbalance=self.height_balance(root.right)

            if(abs(depth_left-depth_right)<=1 and (lbalance is True) and (rbalance is True)):
                
                return True

           

        else:
            return True
        return False

    

    def optimize_balance(self,root,height):

        depth_left=0
        depth_right=0

        if(root):

            lbalance=self.optimize_balance(root.left,depth_left)

            rbalance=self.optimize_balance(root.right,depth_right)

            height=max(depth_left,depth_right)+1

            if(abs(depth_right-depth_left)<=1):

                return lbalance and rbalance

        else:
            return True

        return False


    def maximum(self,root):

        if(root):
            ##data of current node
            rdata=root.data
            ## max data of left subtree
            lmax=self.maximum(root.left)
            ## max data of right subtree
            rmax=self.maximum(root.right)

            return max(rdata,lmax,rmax)
        else:
            return 0

    def minimum(self,root):

        if(root):
            rdata=root.data
            lmin=self.minimum(root.left)
            rmin=self.minimum(root.right)

            return min(rdata,lmin,rmin)
        else:
            return 1000000000000
        
root=node(1)
root.left=node(2)
root.right=node(3)
root.left.left=node(4)
root.left.right=node(5)
root.right.left=node(6)

a=tree()
print(a.minimum(root))
