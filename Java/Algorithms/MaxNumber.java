package Java.Algorithms;

/**
 ** @author Nathan Nasteff
 */

public class MaxNumber {

  /*
   * This function takes an integer as an argument and returns the highest
   * possible number combination that can be made from the original integer.
   */

  public static int getMax(int num) {

    int arr[] = new int[10];
    String str = Integer.toString(num);
    for (int i = 0; i < str.length(); i++) {
      arr[str.charAt(i) - '0']++;
    }

    int max = 0, multiplier = 1;

    for (int i = 0; i <= 9; i++) {
      while (arr[i] > 0) {
        max = max + (i * multiplier);
        arr[i]--;
        multiplier = multiplier * 10;
      }
    }

    return max;
  }

  public static void main(String[] args) {
    int a = 120345676;
    System.out.println("Original number:\n" + a + "\n");
    a = getMax(a);
    System.out.println("Largest number possible:\n" + a + "\n");
  }
}

/*
 ** Sample I/O
 **
 ** INPUT:
 ** 
 ** 120345676
 **
 ** OUTPUT:
 **
 ** Original number: 120345676
 **
 ** Largest number possible: 766543210
 **
 **
 ** Time complexity - O(n)
 **
 ** Space complexity - O(n)
 **
 */
