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
        // To display the result 
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

// Sample INPUT
// find twin prime between 1 - 25 
//sample OUTPUT
// (3, 5)(5, 7)(11, 13)(17, 19)

/*
Time Complexity:

Inside the function :

        bool[] prime = new bool[n + 1];     ------------O(1) 
  
        for (int i = 0; i < n + 1; i++)  ----------------O(n)
            prime[i] = true; 
  
        for (int p = 2; p * p <= n; p++) { 
            // If prime[p] is not changed, 
            // then it is a prime 
              
            if (prime[p] == true) { 
              
                // Update all multiples of p 
                for (int i = p * 2; i <= n; i += p) -------------O(n^2)
                    prime[i] = false; 
            } 
        } 
  
        // check for twin prime numbers 
        // To display the result 
        for (int i = 2; i <= n - 2; i++) {      -----------------O(n)
            if (prime[i] == true && prime[i + 2] == true) 
                Console.Write(" (" + i + ", " + (i + 2) + ")"); 
        } 

Therefore total time = O(1) + O(n) + O(n^2) + O(n) = O(n^2)
*/