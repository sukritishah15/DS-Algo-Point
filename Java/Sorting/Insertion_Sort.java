package Java.Sorting;

import java.util.*;

class Insertion_Sort
{
    public static void main(String args[])
    {
        int n, i, min, j;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array:");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements:");
        for(i = 0; i < n; i++)
        {
            arr[i]= sc.nextInt();
        }
        for(i = 1; i < n; i++)
        {
            min = arr[i];
            for(j = i-1; (j>=0) && (arr[j] > min); j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = min;
        }
        System.out.println("Sorted array is:");
        for(i = 0; i < n; i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}
/*
Problem: Sort the given array using insertion sort.

sample I/O:
Enter the size of array:6
Enter the elements:
34
67
23
14
65
22
Sorted array is:
14 22 23 34 65 67

Enter the size of array:5
Enter the elements:
98 87 76 65 54
Sorted array is:
54 65 76 87 98

Space Complexity: O(1)
Time Complxity: O(n^2) (worst case)
*/

