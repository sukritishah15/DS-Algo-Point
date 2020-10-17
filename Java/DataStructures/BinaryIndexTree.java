package Java.DataStructures;

import java.util.*;

public class BinaryIndexTree {
    static int bit[], n;
    static void update(int x, int val) {
        for (int i=x;i<=n;i+=i&-i) {
            bit[i]+=val;
        }
    }
    static int query(int x) {
        int sum = 0;
        for (int i=x;i>0;i-=i&-i) {
            sum+=bit[i];
        }
        return sum;
    }
    static int query(int l, int r) {
        return query(r) - query(l-1);
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        bit = new int[n+1];
        while(true) {
            int x = in.nextInt(), i, k, l, r;
            if(x==0) break;
            if(x==1) { //increment index i with value k
                i = in.nextInt(); k = in.nextInt();
                update(i, k);
            } else if(x==2) { //query sum of [L, R]
                l = in.nextInt(); r = in.nextInt();
                System.out.println("Sum of the range ["+l+", "+r+"] is "+query(l, r));
            }
        }
    }
}
/*
Sample Input:
10
1
2 5
1
3 5
1
4 2
2
1 3
2
2 4
0
Sample Output:
10
12
Time Complexity: O(logN) queries and updates
Space Complexity: O(N)
*/