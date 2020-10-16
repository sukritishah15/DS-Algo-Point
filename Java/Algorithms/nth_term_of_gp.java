package Java.Algorithms;

import java.util.*;
import java.lang.Math;

public class nth_term_of_gp{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a1 = sc.nextInt();
        int a2 = sc.nextInt();
        int n = sc.nextInt();
        int r = a2 / a1;
        int an = a1 * (int)(Math.pow(r, (n-1)));
        System.out.println(an);
    }
}
/*
Given the first two terms, a1 and a2, of an G.P. (Geometric Progression), and an integer n, find the value of nth term in the G.P.

Sample Input:
a1 = 1
a2 = 2
n=4

Sample Output:
8

Explanation:
The G.P. for this example would be - 1, 2, 4, 8, 16, ...

Time complexity : O(1)
Space complexity: O(1)

*/