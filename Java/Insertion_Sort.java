import java.util.*;

class Insertion_Sort
{
    //Creating method so that it will provide code reusability and maintability of code
    void sort(int arr[]) 
    { 
        int n = arr.length; //to take total number of element in array 
        for (int i = 1; i < n; ++i) { 
            int key = arr[i]; 
            int j = i - 1; 
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
    //printing method
     static void printArray(int arr[]) 
    { 
        int length = arr.length; 
        for (int i = 0; i < length; ++i) 
            System.out.print(arr[i] + " "); 
  
        System.out.println(); 
    } 
    //Main method (Thread start from here  for execution )
    public static void main(String args[])
    {
        Scanner scanner=new Scanner(System.in);
        int arraySize=scanner.nextInt();
        System.out.println("Please! Enter Size of Array");
       int arr[] = new int[arraySize]; 
  
        Insertion_Sort object = new InsertionSort(); //here we are creating our object of our class although we can make our method static to access directly  without creating object
        object.sort(arr); 
         printArray(arr); 
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
Time Complxity: O(n^2) (worst case)S
*/

