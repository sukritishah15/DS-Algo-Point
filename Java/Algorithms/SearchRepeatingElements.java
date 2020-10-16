package Java.Algorithms;

import java.util.HashSet;
import java.util.Set;

public class SearchRepeatingElements {
    public static void main(String args[]){
        int arr[]={1,2,2,5,7,4,5,8,7};
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<arr.length;i++){
            if(!set.add(arr[i])){
                System.out.print(arr[i]+" ");
            }
        }
    }
}
/*
Input - 1,2,2,5,7,4,5,8,7
output - 2 5 7 

Space Complexity - o(n)
Time Complexity - o(n)


*/
