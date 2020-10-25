package Java.Sorting;

/**
 ** @author Nathan Nasteff
 */

public class ShellSort {

	/* 
	** The shell sort algorithm uses a directed insersion sort
	** to first sort widely spaced array elements (length / 2)
	** and then elements that are closer together (length /= 2)
	*/

	public static void shellSort(int arr[]) {

		int a = arr.length;

		for (int interval = a / 2; interval > 0; interval /= 2) {

			for (int i = interval; i < a; i += 1) {

				int temp = arr[i];
				int j;

				for (j = i; j >=  interval && arr[j - interval] > temp; j -= interval)
					arr[j] = arr[j - interval];

				arr[j] = temp;
			}
		}
	}

	public static void main(String[] args) {

		// Test case

		int test[] = new int[] { 30, 10, 12, 1, 4, 6, 2, 19 };
		int i;

		System.out.println("Original Array:");
		for (i = 0; i < test.length; i++) {
			System.out.print(test[i] + " ");
			if (i == (test.length - 1)) {
				System.out.println("\n");
			}
		}

		shellSort(test);

		System.out.println("Sorted Array:");
		for (i = 0; i < test.length; i++) {
			System.out.print(test[i] + " ");
		}
	}
}

/*
** Sample I/O
**
** INPUT:
** 
** 30 10 12 1 4 6 2 19
**
** OUTPUT:
**
** Original Array:
** 30 10 12 1 4 6 2 19
** 
** Sorted Array:
** 1 2 4 6 10 12 19 30
**
** Time Complexity - O(n log n) 
** Space Complexity - O(1)
**
*/
