package Java.Sorting;/*
    Input : size of array and the array 
    Output: Sorted Array
    Algorithm: Mergesort
    Time Complexity: O(n*log n)
    Space Complexity: O(n)
    
    Sample Input and Output:
    Enter the size of the array :5
    Enter the array elements :
     5 4 1 2 3
    Sorted Array :  1 2 3 4 5
    
*/
import java.util.Scanner;

public class MergeSort {
    void merge(int arr[], int l, int m, int r)  // Marge Function 
    { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;    
    int L[] = new int[n1]; // temp arrays
    int R[] = new int[n2];   
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j];   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)  // marging is done in this loop
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
      while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
      while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

    void mergeSort(int arr[], int l, int r) { // recursive merge sort
        if (l < r) {

            int m = l + (r - l) / 2;

            mergeSort(arr, l, m); //left half
            mergeSort(arr, m + 1, r); // right half
            merge(arr, l, m, r); // merge entire array
        }
    }

     static void display(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
      
        System.out.println("Enter the length of the array : ");
        int n=scanner.nextInt();
        int arr[] =new int[n];
        System.out.println("Enter the Elements of the array :\n");
        for(int i=0; i<arr.length; i++ ) {
            arr[i] = scanner.nextInt();
        }
        MergeSort mergeSort=new MergeSort();
        mergeSort.mergeSort(arr, 0, arr.length-1);
        for(int i=0; i<arr.length; i++ ) {
            System.out.print(arr[i]+" ");
        }
    }
}
