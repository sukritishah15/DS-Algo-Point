package Java.Sorting;//Implement Heap Sort(Issue #59)
//https://github.com/sukritishah15/DS-Algo-Point/issues/59
//Contributed by @mephi007 : https://github.com/mephi007
import java.util.Arrays;
import java.util.Scanner;


public class HeapSort {

	public static void main(String[] args) {
		System.out.println("Enter number of elements to be in array");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		System.out.println("Enter elements in the array");
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		System.out.println("Array before sorting");
		System.out.println(Arrays.toString(arr));
		System.out.println("Array after sorting");
		heapSort(arr, n);
		System.out.println(Arrays.toString(arr));
	}

	private static void heapSort(int[] arr, int n) {
		// TODO Auto-generated method stub
		for (int i = n/ 2 ; i >= 0; i--) {
			heapify(arr, i, n);
		}
		for (int i = n-1;i >0 ; i--) {
			swap(arr,0 , i);
			heapify(arr, 0, i-1);
		}
	}

	private static void heapify(int[] a, int index, int end) {
		// TODO Auto-generated method stub
		if (2*index+1 >= end) {
			return;
		}
		int traverse = index;
		int lc = 2 * index + 1;
		int rc = 2 * index + 2;
		int left = lc < end ? a[lc] : Integer.MIN_VALUE;
		int right = rc < end ? a[rc] : Integer.MIN_VALUE;
		int val = Math.max(a[index], Math.max(left, right));
		if (val == left) {
			swap(a, index, lc);
			traverse = lc;
		} else if (val == right) {
			swap(a, index, rc);
			traverse = rc;
		}
		if (traverse != index) {
			heapify(a, traverse, end);
		}
	}

	private static void swap(int[] a, int i, int j) {
		// TODO Auto-generated method stub
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

}
/*-----Input and Ouput ----
 * Enter number of elements to be in array
5
Enter elements in the array
10
20
15
30
40
Array before sorting
[10, 20, 15, 30, 40]
Array after sorting
[10, 15, 20, 30, 40]
----Time Complexity----
heapify takes O(n)
----Space Complexity----
O(n) to store elements in array. 
Actually sorting do not takes any extra space as this is in-place sorting algorithm
*/
