using System;
using System.Linq;

/*
 ** Sample I/O
 **
 ** INPUT: 
 ** 
 ** Two words in each line to compare if they are anagrams.
 **
 ** Example Input: 
 ** CAT
 ** TAC
 **
 ** OUTPUT:
 **
 ** If the strings are anagrams, "The strings are anagrams" is the printed output. Otherwise,
 ** if they are not anagrams, "The strings are not anagrams" is the printed output.
 **
 ** Example Output for previous example input:
 ** The strings are anagrams
 **
 ** Time complexity - O(n)
 **
 ** Space complexity - O(n)
 **
 */					
public class Program
{
	private static bool AreAnagrams(string firstString, string secondString)
	{
		var firstStringChars = firstString.ToLower().ToList();
		var secondStringChars = secondString.ToLower().ToList();
		firstStringChars.Sort();
		secondStringChars.Sort();
		return firstStringChars.SequenceEqual(secondStringChars);
	}
	
	public static void Main()
	{
		Console.Write("Enter the first word: ");
		var firstString = Console.ReadLine();
		Console.Write("Enter the second word: ");
		var secondString = Console.ReadLine();
		var result = AreAnagrams(firstString, secondString);
		if(result)
		{
			Console.WriteLine("The strings are anagrams");
		}
		else
		{
			Console.WriteLine("The strings are not anagrams");
		}
	}
}
