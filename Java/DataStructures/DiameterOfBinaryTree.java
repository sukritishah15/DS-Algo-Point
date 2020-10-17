package Java.DataStructures;

class DiameterOfBinaryTree {

    static int solution = 0;

    public static int findHighest(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftMax = findHighest(root.left);
        int rightMax = findHighest(root.right);

        solution = Math.max(solution, leftMax + rightMax + 1);

        return Math.max(leftMax, rightMax) + 1;

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(3);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(11);
        root.left.right = new TreeNode(12);
        findHighest(root);
        System.out.println("Diameter: "+solution);
    }

    static class TreeNode {
        int value;
        TreeNode left, right;

        public TreeNode(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }
}

/*
Input:
        1
       / \
      3   7
     / \
    11 12
Output:
Diameter: 4

Time complexity: O(n)
Space complexity: O(n)

 */
