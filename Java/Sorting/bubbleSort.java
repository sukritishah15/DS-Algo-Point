package Java.Sorting;

import java.io.IOException;
import java.util.*;

public class bubbleSort {
    public static void main(String args[]) throws IOException
    {
        int n;
        Scanner in=new Scanner(System.in);

        System.out.println("enter size of array");
        n=in.nextInt();

        int a[]=new int[n];                                 //declaring an array a of size n
        System.out.println("enter array elements");

        for(int i=0;i<n;i++)                                //input array elements
        a[i]=in.nextInt();

        for(int i=0;i<n-1;i++)                              //performing bubble sort
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])                             //sorting in ascending order
                {
                    int t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }

        System.out.println("the sorted array is :");
        for(int i=0;i<n;i++)                                //printing the sorted array
        System.out.print(a[i] + " ");

        /*
        Example:

        Input: 6
               5 3 10 2 11 45
        Output: 2 3 5 10 11 45

        Input: 5
               81 21 73 12 90
        Output: 12 21 73 81 90

        Space Complexity: O(1)
        Time Complexity: O(N^2)

        */


    }
    
}
