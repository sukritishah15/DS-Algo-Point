package Java.Sorting; /**
 * @author John Rafael Cadorna
 *
 */

import java.util.Scanner;

public class SelectionSort {
  public static void main (String[] args){
    Scanner in  = new Scanner(System.in);
    System.out.print("array length: ");
    int a[] = new int[Integer.parseInt(in.nextLine())];

    for (int i = 0; i < a.length; i++){
      a[i] = in.nextInt();
    }

    System.out.println("Before:");
    for (int i = 0; i < a.length; i++){
      System.out.print(a[i] + " ");
    }
    sort(a);

    System.out.println("\nAfter:");
    for (int i = 0; i < a.length; i++){
      System.out.print(a[i]+ " ");
    }

    in.close();
  }

  private static void sort(int a[]) {
    int i, j, min;

    for (i = 0; i < a.length; i++){
      min = i;
      for (j = i+1; j < a.length; j++){
        if (a[j] <= a[min]){
          min = j;
        }
      }
      // swap
      int tmp = a[min];
      a[min] = a[i];
      a[i] = tmp;
    }
    
  }
}

/* Sample I/O
 *
 * INPUT:
 *  7
 *  34 1 5 9 3 7 0
 *
 * OUTPUT:
 *  Before:
 *  34 1 5 9 3 7 0
 *  After:
 *  0 1 3 5 7 9 35
 *
 *  space complexity - O(1)
 *  Time Complexity - O(n^2)
 */
