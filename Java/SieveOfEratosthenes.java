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

//Given a number n, print all primes smaller than or equal to n using Sieve of Eratosthenes technique.
//Time complexity O(nlogn)
//space compexity O(n)