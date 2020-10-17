package Java.Algorithms;

import java.util.*;

public class SieveOfEratosthenes{
    
    public static void main(String[] arg){

        Scanner sc= new Scanner(System.in);
        System.out.println("Enter n");
        int n = sc.nextInt();
        //Assume all No. 0 to n is prime(true)
        boolean prime[] = new boolean[n+1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        //check whether a no. is prime or not 
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                // if no. is not prime then the all of it's multiples 
                //are not prime so make them not prime(false)
                for(int j = i*i;j<=n;j+=i){
                    prime[j] = false;
                }
            }
        }
        //Print all prime numbers less then or equal to n
        for(int i=2;i<=n;i++){
            if(prime[i]){
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
/*
User has to input the number n and the algorithm will give all the primes
smaller than or equal to n using Sieve of Eratosthenes.
Time complexity : O(n*log(log(n)))
Space complexity : O(n)
For example - 
Input: 4
Output : 2 3
Input : 10
Output: 2 3 5 7
*/
