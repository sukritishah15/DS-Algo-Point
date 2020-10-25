package Java.Algorithms;

import java.util.Scanner;

public class RotateClockwise {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n=sc.nextInt();
        int [] arr=new int[n];
        System.out.println("Enter the elements of array: ");
        for(int i=0;i<n;i++)
        {
          arr[i]=sc.nextInt();
        }
        System.out.println("Enter the no of rotations of elements :");
        int r=sc.nextInt();
        int rotations=r%n;
        System.out.println("Array after rotation is: ");
        for(int i=rotations;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
        for(int i=0;i<rotations;i++)
        {
            System.out.print(arr[i]+" ");
        }
        
    }
}

//Implement rotation of array by d elements
// Input/Output

// Input
// Enter the size of Array
// Enter the elemnets 
// Enter the number of rotations
// Output
// Array after rotation is: Rotated Array

// Example :Suppose array is {1,2,3,4,5,6}
//          no. of rotaion is 3
// Ans : Array after rotation is : {4,5,6,1,2,3}

// Time Complexity:O(n);
// Space Complexity:O(1);





