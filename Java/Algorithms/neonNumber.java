package Java.Algorithms;

import java.util.*;
import java.lang.Math;

public class neonNumber{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = n * n;
        int ans = 0;
        while(s>0){
            ans += (s%10);
            s = (int)Math.floor(s/10);
        }
        if (ans == n){
            System.out.println("Neon number");
        }
        else{
            System.out.println("Not a neon number");
        }
    }
}
/*
A simple program to check whether the entered number by the user is neon or not.
A neon number is a number where the sum of digits of square of the number is equal to the number.

Sample Input:
9

Sample Output:
Neon number

Explanation: Sum of digits of it's square = (8 + 1) = 9 = number entered by the user
So, 9 is a NEON NUMBER.

Time complexity : O(log N^2)
Space complexity: O(1)
*/