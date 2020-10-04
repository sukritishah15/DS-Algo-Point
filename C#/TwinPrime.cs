// C# program to illustrate.. 
// print all twin primes 
// Using Sieve of Eratosthenes 
using System; 
  
public class GFG { 
  
    public static void printtwinprime(int n) 
    { 
  
        // Create a boolean array "prime[0..n]" 
        // and initialize all entries it as  
        // true. A value in prime[i] will 
        // finally be false if i is Not a  
        // prime, else true. 
        bool[] prime = new bool[n + 1]; 
  
        for (int i = 0; i < n + 1; i++) 
            prime[i] = true; 
  
        for (int p = 2; p * p <= n; p++) { 
            // If prime[p] is not changed, 
            // then it is a prime 
              
            if (prime[p] == true) { 
              
                // Update all multiples of p 
                for (int i = p * 2; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
  
        // check for twin prime numbers 
        // To display th result 
        for (int i = 2; i <= n - 2; i++) { 
            if (prime[i] == true && prime[i + 2] == true) 
                Console.Write(" (" + i + ", " + (i + 2) + ")"); 
        } 
    } 
  
    // Driver Code 
    public static void Main() 
    { 
        // static input 
        int n = 25; 
          
  
        // calling the function 
        printtwinprime(n); 
    }    
}

// OUTPUT
// (3, 5)(5, 7)(11, 13)(17, 19)