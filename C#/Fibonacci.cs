using System;

/*
 ** Sample I/O
 **
 ** INPUT:
 ** 
 ** "n". Being "n" a positive integer number.
 **
 ** OUTPUT:
 **
 ** Sum till nth term.
 **
 ** Time complexity - O(n)
 ** 
 ** Space complexity - O(1)
 **
 */				
public class Program
{
	private static int Fibonacci(int n)
	{
		var n0 = 0;
		var n1 = 1;
		if(n == 0)
		{
			return 0;
		}
		else if(n == 1)
		{
			return 1;
		}

		var i = 2;
		var result = 1;
		while(i <= n)
		{
			result = n0 + n1;
			n0 = n1;
			n1 = result;
			i++;
		}
		return result;
	}
	
	public static void Main()
	{
		Console.Write("Enter the value of n: ");
		var n = Console.ReadLine();
		int num;
		if(int.TryParse(n, out num))
		{
			var result = Fibonacci(num);
			Console.WriteLine("The result is: " + result);
		}
		else
		{
			Console.WriteLine("n must be a number");
		}
	}
}