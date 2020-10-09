package Java.Algorithms;

public class GCD_1{
    public static long gcd(long a, long b) {
        return b == 0 ? (a < 0 ? -a : a) : gcd(b, a % b);
      }
    public static void main(String[] args) {
        System.out.println(gcd(12,18)); // output-> 6
        System.out.println(gcd(27,3));// output-> 3

        /* Sample Input - 6 14
           Sample output - 2
           Time Complexity - O(log(a+b))
           Space Complexity - O(1)*/
    }
}