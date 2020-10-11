package Java.DataStructures;

import java.io.*;
import java.util.*;


public class HeightOfBinaryTree {

    private static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        public TreeNode(int val) {
            this.value = val;
            this.left = null;
            this.right = null;
        }
    }

    public static void main(String[] args) {
        TreeNode root = null;
        root = new TreeNode(10);
        root.left = new TreeNode(7);
        root.right = new TreeNode(14);
        root.right.left = new TreeNode(17);
        root.right.left.right = new TreeNode(24);
        root.left.left = new TreeNode(20);
        /*
                        10
                       /  \
                      7    14
                     /    /
                    20   17
                           \
                            24
         */
        System.out.println("-- Tree --");
        inOrder(root);
        System.out.println("\n-- Height of the root -- ");
        System.out.println(getHeight(root));
        System.out.println("-- Height of the left subtree -- ");
        System.out.println(getHeight(root.left));
        System.out.println("-- Height of the right subtree -- ");
        System.out.println(getHeight(root.right));
    }

    //InOrder Traversal to print nodes
    private static void inOrder(TreeNode root) {
        // TODO Auto-generated method stub
        if (root == null) {
            return;
        }
        inOrder(root.left);
        System.out.print(root.value + " ");
        inOrder(root.right);

    }

    //height of the tree
    private static int getHeight(TreeNode root) {
        if(root == null) {
            //height of null tree is zero
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
		/*
					10
				   /  \
		          5    20
		              /
		             12

		        height of left subrtree = 1
		        height of right subrtree = 2
		        heifht of root = max(1 , 2) + 1 = 3
		 */
        return Math.max(leftHeight , rightHeight) + 1;
    }
}

/*

--Tree--                // inorder traversal of the root
20 7 10 17 24 14

//height of root and its sub trees

-- Height of the root --
4
-- Height of the left subtree --
2
-- Height of the right subtree --
3

[n = number of nodes]

Time complexities

getHeight -> O(n)
inorderTraversal -> O(n)

Space Complextiy
O(n) -> for storing all nodes n nodes

 */