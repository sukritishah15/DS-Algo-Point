package Java.Algorithms;

import java.util.Arrays;
import java.util.Scanner;

public class Inversion {
    public static void main(String[] args) {
	    int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Elements ");
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the array values ");
        for(int i =0;i<n;++i)
            arr[i]=sc.nextInt();

        System.out.println(merge(arr,0,arr.length-1));
    }
    private static int mergeCount(int[] arr, int l,int m , int r){
        int[] left = Arrays.copyOfRange(arr,l,m+1);
        int[] right = Arrays.copyOfRange(arr,m+1,r+1);

        int inv=0;
        int i =0, j =0, k = l;
        while(i<left.length&&j<right.length){
            if(left[i]<=right[j])
                arr[k++]=left[i++];
            else {
                arr[k++]= right[j++];
                inv  = inv + (m+1)-(l+i);
            }
        }
        while (i<left.length)
            arr[k++]= left[i++];

        while(j<right.length)
            arr[k++] =  right[j++];

        return  inv;

    }
    private static int merge(int[] arr, int l , int r){
        int cnt = 0;
        if(l<r){
            int m= (l+r)/2;
            cnt+= merge(arr,l,m);
            cnt+= merge(arr,m+1,r);
            cnt+= mergeCount(arr,l,m,r);
        }
        return cnt;
    }
}

/* Sample Input: 8 4 2 1
   Sample Output: 6 
   Time Complexity: O(nlogn)
   Space Complexity: O(n) */
