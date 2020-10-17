package Java.Algorithms;

import java.util.Scanner;

public class CheckForArmstrongNo {

    public static void main(String[] args) {

        /* Check whether a given number is armstring is not */

        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int temp, result = 0, rem;
        temp = number;

        while(temp > 0) {
            rem = temp % 10;
            temp /= 10;
            result = result + (rem * rem * rem);
        }

        if(number == result) {
            System.out.println(number+" is an armstrong number");
        }
        else {
            System.out.println(number+" is not an armstrong number");
        }
    }
}
        /*

        Sample I/O:
            Enter a number:153
            153 is an armstrong number.

            Enter a number:247678687
            247678687 is not an armstrong number.

            Time Complexity: O(log N) (a number N has log N digits)
            Space Complexity: O(1)
        */

