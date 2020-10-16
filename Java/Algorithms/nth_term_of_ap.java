package Java.Algorithms;

import java.util.*;
import java.lang.*;

/**
 * nth_term_of_ap
 */
public class nth_term_of_ap {
    private static Scanner scanner=new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter the first term of A.P.");
        int t1 = scanner.nextInt();
        scanner.nextInt();

        System.out.println("Enter the second term of A.P.");
        int t2 = scanner.nextInt();
        scanner.nextInt();

        System.out.println("Write the position of the term you want to find out ");
        int n = scanner.nextInt();
        scanner.nextLine();

        System.out.println("The "+n+"th term of the A.P. equals");
        System.out.println(t1+((n-1)*(t2-t1)));
        
        /* sample input 
         Let the first term be 2 and second term be 5. Also let the value of n be 5
         The programs calculates the nth term by using formula of ap i.e. a+ (n-1)d
         Output is 14. 
         This code is contributed by Manan Chawla
         Time Complexity is O(1) and space complexity is O(1)
         */
        

    }
}

