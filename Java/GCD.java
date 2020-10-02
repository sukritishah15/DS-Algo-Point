/**
 ** @author Nathan Nasteff
 **
 */

public class GCD {

  /*
   * The Euclidian Algorithm for getting the greatest common denominator of two
   * integers operates by performing modulo operation (b % a) recursivley (which
   * then turns to a % b) until the the result of the modulo operation reaches 0.
   * This function takes two int args and returns an int (GCD)
   */

  public static int getGCD(int a, int b) {

    if (a == 0)
      return b;

    return getGCD(b % a, a);
  }

  public static void main(String[] args) {

    // Test case

    int a = 111;
    int b = 9;
    int GCD = getGCD(a, b);
    System.out.println("\nGreatest common factor of " + a + " and " + b + ":\n" + GCD);

  }

}

/*
 ** Sample I/O
 **
 ** INPUT:
 ** 
 ** 111 9
 **
 ** OUTPUT:
 **
 ** Greatest common factor of 111 and 9: 3
 **
 ** Time complexity - O(log(a + b))
 **
 ** Space complexity - O(1)
 **
 */