package Java.Algorithms;

import java.io.*;
import java.util.*;


public class TheDutchNationalFlag {

    private static void swap(int arr[] , int i , int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void sort(int a[] , int n) {
        // we want to divide the array in three half
        // left - 0's
        // centre - 1's
        // right - 2's

        int start = 0;      // start represents the index where next zero is to be placed
        int end = n - 1;    // end represents the index where next two is to be placed

        int i = 0; // i pointer iterates over array until high is hit

        while(i < end) {
            if(a[i] == 0) {
                // if current num is 0 push it to left side and move i ahead
                swap(a , i , start);
                start++;
                i++;
            }
            else if(a[i] == 1) {
                // if current num is 1 dont push it either of the left or right side and move i ahead
                i++;
            }
            else {
                // if current num is 2 push it to right side
                swap(a, i, end);
                end--;
            }
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        System.out.println("---Enter no of elements---");
        int n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        System.out.println("---Enter elements---");
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < n ; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println("---unsorted array---");
        System.out.println(Arrays.toString(a));

        sort(a , n);

        System.out.println("---sorted array---");
        System.out.println(Arrays.toString(a));


    }

}

/*

---Enter no of elements---
6
---Enter elements---
2 0 1 1 2 0
---unsorted array---
[2, 0, 1, 1, 2, 0]
---sorted array---
[0, 0, 1, 1, 2, 2]

Time Complexity
O(n)

Space Complexity
O(1) -> no extra space used other than storing value of array

 */