/*
Two strings, s1  and s2, are called anagrams if they contain all the same characters in the same frequencies. 

For example, the anagrams of CAT are CAT, ACT, TAC, TCA, ATC, and CTA.
*/
import java.util.*;
class Anagrams
{
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        // Taking input from the user
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();

        //Storing the result and printing it.
        boolean result = isAnagram(s1, s2);
        System.out.println(result);

    }
    public static boolean isAnagram(String a,String b)
    {
        //Auxillary array to store the count of the characters present in the strings
        int arr[] = new int[256];

        //Coverting both the strings to character arrays to store the count of each character in the auxillary array.
        char a1[] = a.toCharArray();
        char b1[] = b.toCharArray();

        // To store the sum of the elements of the auxillary array
        int c = 0;

        /* The auxillary array indexes actually represents the ASCII codes of the characters for all the characters in the Strings.
            If any character is found, then the value of the character index position in the auxillary array increases by 1 every time
            so it is first passed through the first string(i.e where value increases) and then passed through the second string(i.e where
            value decreses) and all the elements of the auxillary array becomes 0.*/
        for(int i=0;i<a1.length;i++)
        {
            arr[a1[i]]++;
        }
        for(int i=0;i<b1.length;i++)
        {
            arr[b1[i]]--;
        }

        for(int i=0;i<256;i++)
        {
            c += Math.abs(arr[i]);
        }
        
        // Checking whether the values of the auxillary array are null or not.
        if(c==0)
            return true;
        else
            return false;
    }
}
/*
Input:

The first line contains a lowercase string denoting s1.
The second line contains a lowercase string denoting s2.

Output:

Print "true" if s1 and s2 are case-insensitive anagrams of each other; otherwise, print "false" instead.

Example 1:

Input 1:

anagram
margana

Output 1:

true

Input 2:

anagramm
marganaa

Output 2:

false

Time Complexity : O(N + M), N and M are the lengths of Strings s1 & s2 respectively.
Space Complexity : O(N + M), N and M are the lengths of Strings s1 & s2 respectively.

*/