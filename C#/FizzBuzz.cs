using System;

/*
 ** Sample I/O
 **
 ** INPUT: 
 ** 
 ** None
 **
 ** OUTPUT:
 **
 ** For each number from 1 to 100, one of these will be printed (each of them in separate lines):
 ** "Fizz" if the number is multiple of 3, "Buzz" if the number is multiple of 5 
 ** and "FizzBuzz" if the number is multiple of both. Otherwise, the number is printed.
 **
 ** Time complexity - O(n)
 **
 ** Space complexity - O(n)
 **
 */
public class Program
{
	public static void Main()
	{
		var i = 1;
		while(i<=100)
		{
			if(i%3 == 0 && i%5 == 0)
			{
				Console.WriteLine("FizzBuzz");
			}
			else if(i%3 == 0)
			{
				Console.WriteLine("Fizz");
			}
			else if(i%5 == 0)
			{
				Console.WriteLine("Buzz");
			}
			else
			{
				Console.WriteLine(i);
			}
			i++;
		}
	}
}