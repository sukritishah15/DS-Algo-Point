package Java.Algorithms;

import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc= new Scanner(System.in);
        /*
        Sample input:
        size=8
        arr[]={-2, -3, 4, -1, -2, 1, 5, -3}; 
        
        Sample output: 7
        */
        int size=sc.nextInt();
        int[] arr=new int[size];
         for(int i=0;i<arr.length;i++){
             arr[i]=sc.nextInt();
         }
        int ans=maximumSumSubarray(arr);
        System.out.println("Maximum Sum is "+ans);
   }
    
   public static int maximumSumSubarray(int[] arr){
       int max=Integer.MIN_VALUE;
         int temp=0;
       for(int i=0;i<arr.length;i++){
         temp+=arr[i];
         if(max < temp){
             max=temp;
         }
         if(temp < 0){
             temp=0;
         }
       }
       return max;
   }
}

/*  The time complexity of Kadane's algorithm is O(n) because there is only one for loop which scans the entire array exactly once. */
/* The space complexity is O(1).*/
