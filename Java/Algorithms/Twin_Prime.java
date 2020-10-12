package Java.Algorithms;/*  Program to print all twin prime numbers present in a given range */

import java.util.*;

class Twin_Prime
{
    boolean isPrime(int n)
    {//Function to check if the integer is prime or not
        int c = 0;
        for(int i=1; i<=n; i++)
        {
            if (n%i == 0)
            c++;
        }
        if (c == 2)
            return true; //n is a prime number
        else
            return false; //n is a not prime number
    }

    void main()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please enter the start of the range:");
        int start = sc.nextInt();
        System.out.println("Please enter the end of the range:");
        int end = sc.nextInt();
        for (int i=start; i<=end; i++)
        {
            int a = i;
            int b = i+2;
            boolean r1 = isPrime(a);
            boolean r2 = isPrime(b);
            if ( r1 && r2)
            System.out.println(a + " " + b);
        }
    }
}


/*
Example:
Please enter the start of the range:
5
Please enter the end of the range:
29
5 7
11 13
17 19
29 31

Time Complexity: O(logn)
Space Complexity: O(1)
*/
