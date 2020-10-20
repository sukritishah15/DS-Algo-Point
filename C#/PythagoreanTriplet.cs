using System;

/*
 ** Sample I/O
 **
 ** INPUT: 
 ** 
 ** The program will ask to enter three numbers in separate lines. 
 ** The two first numbers must correspond to the legs of the triangle. 
 ** The third one will be the hypotenuse.
 **
 ** Example Input:
 ** 3 
 ** 4
 ** 5
 **
 ** OUTPUT:
 **
 ** If the three numbers constitue a Pythagorean Triplet, "These numbers are a Pythagorean triplet" is printed.
 ** Otherwise, if they are not a Pythagorean Triplet, "These numbers are not a Pythagorean triplet" is the 
 ** printed output. 
 **
 ** Example Output for previous example input:
 ** These numbers are a Pythagorean triplet
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
		Console.Write("Enter the number of the first triangle's leg: ");
		var firstNumber = int.Parse(Console.ReadLine());
		Console.Write("Enter the number of the second triangle's leg: ");
		var secondNumber = int.Parse(Console.ReadLine());
		Console.Write("Enter the number of the hypotenuse: ");
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
