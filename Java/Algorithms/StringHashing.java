package Java.Algorithms;

import java.util.*;

public class StringHashing {

    static int[] frqA = new int[26], frqB = new int[26];
    static long seed = 131, mxn = (long)2e5+5;
    static long[] pow = new long[mxn], hash = new long[mxn];
    static boolean check(int a[], int b[]) {
        for (int i=0;i<26;i++) {
            if(a[i]!=b[i]) return false;
        } return true;
    }
    static long getHash(int l, int r) {
        return hash[r] - hash[l-1]*pow[r-l+1];
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a = in.nextLine(), b = in.nextLine();
        HashSet<Long> set = new HashSet(); //used to count frequencies
        pow[0] = 1; 
        for (int i=1;i<=b.length();i++) {
            hash[i] = hash[i-1]*seed + b.charAt(i-1); //hashing the string
            pow[i] = pow[i-1]*seed; //precalculating powers of the seed
        }
        for (int i=0;i<a.length();i++) { //calculating frq of the needle
            frqA[a.charAt(i)-'a']++;
        }
        for (int i=1;i<=b.length();i++) {
            frqB[b.charAt(i-1)-'a']++;
            if(i>a.length()) frqB[b.charAt(i-a.length()-1)-'a']--;
            if(check(frqA, frqB)) set.add(getHash(i-a.length()+1, i));
        }
        System.out.println(set.size());
    }
}
/*
Description:
- Given a string N, the needle, and a string H, the haystack, find the number
of disctice permutations of which N apperas in H.
Input specification:
- String N, H where N<=H in length and H<=2e5
Output specification:
- The number of distinct permutation s of N which appear as a substring of H
Sample Input:
aab
abacabaa
Sample Output:
2
Time Complextiy: O(n) preprocessing with O(1) queries
Space Complexity: O(n)
*/