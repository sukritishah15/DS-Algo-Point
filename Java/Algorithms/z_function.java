package Java.Algorithms; /**
Implementation of Z Function
https://github.com/sukritishah15/DS-Algo-Point/issues/134
Contributed by @jhoserpacheco : https://github.com/jhoserpacheco
*/


/*
Given a string s it returns an array z where z [i] is equal to the greatest
number of characters from s [i] that match the characters from s [0]
*/

static int[] z_function(String ss) {
    StringBuilder s = new StringBuilder(ss);
    int n = s.length();
    int[] z = new int[n];
    for (int i = 1, x = 0, y = 0; i < n; i++) {
        z[i] = Math.max(0, Math.min(z[i - x], y - i + 1));
        while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) {
            x = i; y = i + z[i]; z[i]++;
        }
        return z;
    }

    public static void main(String args[]){
      String str = "BAAABAA";
      int arrayTemp[] = z_function(str);
      int maximum = -1;
      for(int i : arrayTemp){
        maximum = Math.max(maximum, i);
      }
      System.out.println(maximum);
    }
}


/*

Sample I/O-

Input
BAAABAA

Ouput
max in z_function: 3

Time Complexity - O(n)
Space Complexity - O(n)

*/
