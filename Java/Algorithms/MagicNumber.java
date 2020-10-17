package Java.Algorithms;

import java.io.*;

public class MagicNumber {
    static boolean fun(long x) {
        if((int)Math.log10(x)+1==1) return x==1;
        return fun(sum(x));
    }
    static long sum(long x) {
        long n = 0; String s = String.valueOf(x);
        for (int i=0;i<s.length();i++) {
            n+=s.charAt(i)-'0';
        }
        return n;
    }
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        long x = in.nextLong();
        System.out.println(fun(x));
    }
}
/*
Sample Input: the number
100
Sample Output: whether the number satisifies the magic number property
true
Time complexity: at most O(L) where L is the length of the integer
Space complexity: O(1)
*/