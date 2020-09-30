import java.util.Scanner;

class TreeNode {
	int value;
	TreeNode left;
	TreeNode right;

	public TreeNode(int val) {
		this.value = val;
		this.left = null;
		this.right = null;
	}
}

public class ImplementingBST {
	static TreeNode root = null;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.println("---Insert Implementation---");
		System.out.println("How many elements do you want to insert");
		int n = sc.nextInt();
		System.out.println("Enter elements to BST");
		do {
			int ele = sc.nextInt();
			root = insertToBST(root, ele);
			System.out.println("Successfully inserted " + ele);
			System.out.println("BST looks like ");
			inOrderBST(root);
		} while (n-- > 1);
		System.out.println();
		System.out.println("---Searching Impelementation--");
		System.out.println("Enter element to search");
		int ele = sc.nextInt();
		boolean found = searchElementInBST(root, ele);
		if (found) {
			System.out.println("Found " + ele);
		} else {
			System.out.println("Did not Find " + ele);
		}
		System.out.println("---Delete Implementation---");
		System.out.println("Enter element to deleted");
		ele = sc.nextInt();
		root = deleteElementFromBST(root, ele);
		System.out.println("---After deletion, BST looks like---");
		inOrderBST(root);

	}

	private static TreeNode deleteElementFromBST(TreeNode root, int ele) {
		// TODO Auto-generated method stub
		if (root == null) {
			return root;
		}
		if (ele < root.value) {
			root.left = deleteElementFromBST(root.left, ele);
		} else if (ele > root.value) {
			root.right = deleteElementFromBST(root.right, ele);
		} else {
			if (root.left == null)
				return root.right;
			else if (root.right == null)
				return root.left;
			root.value = minValue(root.right);
			root.right = deleteElementFromBST(root.right, root.value);
		}

		return root;
	}
	

	private static int minValue(TreeNode root) {
		// TODO Auto-generated method stub
		  int minv = root.value; 
	        while (root.left != null) 
	        { 
	            minv = root.left.value; 
	            root = root.left; 
	        } 
	        return minv; 
	}

	private static boolean searchElementInBST(TreeNode root, int ele) {
		// TODO Auto-generated method stub
		if (root == null) {
			return false;
		}
		if (ele == root.value) {
			return true;
		}

		if (ele < root.value) {
			return searchElementInBST(root.left, ele);
		}

		return searchElementInBST(root.right, ele);
	}

	private static void inOrderBST(TreeNode root) {
		// TODO Auto-generated method stub
		if (root == null) {
			return;
		}
		inOrderBST(root.left);
		System.out.print(root.value + " ");
		inOrderBST(root.right);

	}

	private static TreeNode insertToBST(TreeNode root, int ele) {
		// TODO Auto-generated method stub
		if (root == null) {
			root = new TreeNode(ele);
			return root;
		}
		if (ele < root.value) {
			root.left = insertToBST(root.left, ele);
		} else {
			root.right = insertToBST(root.right, ele);
		}
		return root;
	}

}
