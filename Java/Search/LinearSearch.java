package Java.Search;// import java.io.*;
// import java.util.Scanner;  Uncomment to take user input

class LinearSearch{

    /* Iterate through each elements and compare it with item to get the element postion break out if found */

    private static int search(int[] a,int item)
    {
        for (int i=0;i<a.length;i++ ) {
            if(a[i]==item){
                return i;
            }
        }
        return -1;
    }

    public static void main(String args[])
    {
        int a[] = {22,18,11,6,3,17,45,30};
        int n = a.length;

        // System.out.println("Enter the element to  be searched: ");
        // Scanner s = new Scanner(System.in);
        // int item = s.nextInt();              // Uncomment to take user input

        int item = 17;
        int pos = search(a,item);
        if(pos != -1){
            System.out.println("The element "+item+" is at postion:- "+(++pos));
        }else{
            System.out.println("Element :- "+item+" not found");
        }
    }

}

/*

Implementation of Linear Search in Java


Sample I/O-

Input - {22,18,11,6,3,17,45,30} item = 17
Output - Element Found at pos 6 (or in absensce Element : 17 not found)

Time Complexity - O(n)
Space Complexity - O(1)

*/
