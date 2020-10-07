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
