package Java.Algorithms;

import java.util.Scanner;

public class FizzBuzz {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please specify the number to calculate to:");
        int amount = scanner.nextInt();

        for (int i = 0; i <= amount; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                System.out.println("FizzBuzz");
            } else if (i % 5 == 0) {
                System.out.println("Buzz");
            } else if (i % 3 == 0) {
                System.out.println("Fizz");
            } else {
                System.out.println(i);
            }
            System.out.println();
        }
    }

}

/*
Sample I/O
100

Output:
Multiple of 3: Fizz
Multiple of 5: Buzz
Multiple of 3 & 5 : FizzBuzz
Else: Number

Time complexity: O(n)
Space complexity: O(n)

 */
