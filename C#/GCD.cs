// C# program to find GCD of two
// numbers
using System;
 
class GFG {
     
    // Recursive function to return
    // gcd of a and b
    static int gcd(int a, int b)
    {
         
        // Everything divides 0 
        if (a == 0)
          return b;
        if (b == 0)
          return a;
     
        // base case
        if (a == b)
            return a;
     
        // a is greater
        if (a > b)
            return gcd(a - b, b);
             
        return gcd(a, b - a);
    }
     
    // Driver method
    public static void Main() 
    {
        int a = 98, b = 56;
        Console.WriteLine("GCD of "
          + a +" and " + b + " is "
                      + gcd(a, b));
    }
}

/*

OUTPUT:

GCD of 98 and 56 is 14



TIME COMPLEXITY:
The time complexity for the above algorithm is O(log(min(a,b))) 
the derivation for this is obtained from the analysis of the worst-case scenario. 
What we do is we ask what are the 2 least numbers that take 1 step, those would be (1,1). 
If we want to increase the number of steps to 2 while keeping the numbers as low as possible as
 we can take the numbers to be (1,2). Similarly, for 3 steps, the numbers would be (2,3),
  4 would be (3,5), 5 would be (5,8). So we can notice a pattern here, for the nth step 
  the numbers would be (fib(n),fib(n+1)).  So the worst-case time complexity would be O(n) 
  where a>= fib(n) and b>= fib(n+1). 

Now Fibonacci series is an exponentially growing series where the ratio of nth/(n-1)th term 
approaches (sqrt(5)-1)/2 which is also called the golden ratio. 
So we can see that the time complexity of the algorithm increases linearly 
as the terms grow exponentially hence the time complexity would be log(min(a,b))!
*/