using System;

/*
 ** Sample I/O
 **
 ** INPUT: 
 ** 
 ** The program will ask to enter three numbers in separate lines.
 **
 ** OUTPUT:
 **
 ** If the three numbers constitue a Pythagorean Triplet, "These numbers are a Pythagorean triplet" is printed.
 ** Otherwise, if they are not a Pythagorean Triplet, "These numbers are not a Pythagorean triplet" is the 
 ** printed output. 
 **
 ** Time complexity - O(n)
 **
 ** Space complexity - O(n)
 **
 */					
public class Program
{
	private static bool PythagoreanTriplet(int firstNumber, int secondNumber, int thirdNumber)
	{
		return (firstNumber^2 + secondNumber^2) == (thirdNumber^2);
	}
	
	public static void Main()
	{
		Console.Write("Enter the first number: ");
		var firstNumber = int.Parse(Console.ReadLine());
		Console.Write("Enter the second number: ");
		var secondNumber = int.Parse(Console.ReadLine());
		Console.Write("Enter the third number: ");
		var thirdNumber = int.Parse(Console.ReadLine());
		var result = PythagoreanTriplet(firstNumber, secondNumber, thirdNumber);
		if(result)
		{
			Console.WriteLine("These numbers are a Pythagorean triplet");
		}
		else
		{
			Console.WriteLine("These numbers are not a Pythagorean triplet");
		}
	}
}