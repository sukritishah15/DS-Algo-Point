using System;
					
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