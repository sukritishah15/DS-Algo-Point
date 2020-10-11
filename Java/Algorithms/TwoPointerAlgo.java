package Java.Algorithms;

import java.util.Arrays;
import java.util.Scanner;

public class TwoPointerAlgo {
    public static void main(String args[])
    {
//        This is a very efficient and effective way to find a pair of numbers in a Sorted Array
//        Suppose we have to find a pair of numbers from a sorted array that matches a particular value
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int N = sc.nextInt();
        int [] array = new int[N];
        System.out.println("Enter the elements of the array in a Sorted Array");
        for(int i=0;i<N;i++)
        {
            array[i] = sc.nextInt();
        }
        System.out.println("Enter the sum that you want to find from the array");
        int req_sum = sc.nextInt();
        Arrays.sort(array);
//        Now we have to take two pointers j and k representing
//        the Head and Tail elements of the array respectively
        int j =0;    //head-pointer
        int k= N-1;  //tail-pointer
        int flag= 0;
        while(j<k)
        {
            if(array[j]+array[k]==req_sum) {
                System.out.println(array[j]+ " and "+ array[k] + " is the pair"); //pair has been found
                break;
            }
            else if (array[j]+array[k] < req_sum)
                j++; //moving towards higher values
            else
                k--; //moving towards lesser values
        }
    }
}
// Input :
// array = [ 10,25,1,30]
//req_sum = 26
//Output :
//25 and 1 is the pair

//Time Complexity : O(n) 
// Space Complexity : O(1)

