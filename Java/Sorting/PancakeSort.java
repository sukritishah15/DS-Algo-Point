package Java.Sorting; /**
 ** @author Rishabh Sudan
 **
 */
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Arrays;
import java.util.Collections;
/*
Pancake sorting.....
Take n as number of elements in the array
Array : a[0,1....n-1]
Sort the array using pancake sort and print the sorted array elements

Sample I/O
input :
6
6 5 4 3 2 1
Output:
1 2 3 4 5 6 */

public class PancakeSort {

    public static void flip(int arr[] , int i){

    for(int j = 0 ; j <= (i / 2) ; j++)
        {
            int temp1 = arr[i-j] ;
            arr[i-j] = arr[j] ;
            arr[j] = temp1 ;
        }
    }
    // time complexity = O(n) ; Space complexity = O(1) 

    public static int max_element(int arr[] , int n){
        int maks = arr[0] ;
        int temp = 0 ;
        for(int i = 1 ; i < n ; i++)
        {
            if(maks < arr[i])
            {
                maks = arr[i] ;
                temp = i ;
            }
        }
        return temp ;
    }

    public static void pancake_sort(int arr[], int n) {
        int curr_size=n ;
        while(curr_size > 0){

            int max_index = max_element(arr , curr_size) ;// time complexity = O(n) ; space complexity = O(1);

            if(max_index !=curr_size -1)
            {
                flip(arr, max_index);
                flip(arr, curr_size -1) ;
            }

            curr_size-- ;

        }
    }
//time complexity = O(n * max(p, q)) where p is the time complexity of flip() and q is the complexity of max_element(); space complexity = O(1)
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); //reading n

        int[] arr = new int[n];

        String[] arrItems =br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        pancake_sort(arr,n);

        for (int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}//Overall time complexity = O(n) ; Overall Space complexity = O(1) 
