// Program to swap two numbers without 
// using temporary variable 
using System; 

class Swap { 
	public static void Main() 
	{ 
		int x = 10; 
		int y = 5; 

		x = x + y; 
		y = x - y; 
		x = x - y; 
		Console.WriteLine("After swapping: x = "
						+ x + ", y = " + y); 
	} 
}
/*
 ** Sample I/O
 **
 ** INPUT: x = 10 
 	   y = 5
 
 ** OUTPUT: x = 5
 **         y = 10
 ** Sum till nth term.
 **
 ** Time complexity - O(n)
 ** 
 ** Space complexity - O(1)
 **
 */			
