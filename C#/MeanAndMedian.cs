using System;
using System.Linq;

class Program
{
	/// <summary>
	/// Takes one or more numbers, or an array of numbers, and returns their mean.
	/// </summary>
	/// <example>
	/// The following code demonstrates how to use <see cref="Mean"/> with an
	/// array of numbers.
	/// <code>
	/// double[] numbers = new double[] { 1, 2, 4, 5 };
	/// Console.WriteLine("Mean: " + Mean(numbers));
	///
	/// /*
	///  This code produces the following output:
	///
	///  Mean: 3.0
	/// */
	/// </code>
	/// </example>
	/// <remarks>
	/// Time complexity is O(n), all numbers need to be summed.
	/// Space complexity is O(0), no allocations are performed.
	/// </remarks>
	public static double Mean(params double[] numbers)
	{
		return numbers.Sum() / numbers.Length;
	}

	/// <summary>
	/// Takes one or more numbers, or an array of numbers, and returns their
	/// median.
	/// </summary>
	/// <example>
	/// The following code demonstrates how to use <see cref="Median"/> with an
	/// array of numbers.
	/// <code>
	/// double[] numbers = new double[] { 2, 4, 6, 8 };
	/// Console.WriteLine("Median: " + Median(numbers));
	///
	/// /*
	///  This code produces the following output:
	///
	///  Median: 5.0
	/// */
	/// </code>
	/// </example>
	/// <remarks>
	/// Time complexity is dependent on <see cref="Enumerable.OrderBy"/> and
	/// will therefor be O(n log n).
	/// Space complexity is O(n), an allocation is performed for the sorted
	/// array.
	/// </remarks>
	public static double Median(params double[] numbers)
	{
		double[] ordered = numbers.OrderBy(n => n).ToArray();
		if (ordered.Length % 2 == 0)
		{
			// Median of an even numbered collection is the mean of the middle two
			// elements.
			return Mean(ordered[ordered.Length / 2], ordered[ordered.Length / 2 + 1]);
		}
		else
		{
			return ordered[ordered.Length / 2];
		}
	}

	public static void Main(string[] args)
	{
		// Parses all arguments as doubles and makes an array out of them
		double[] numbers = args.Select(Double.Parse).ToArray();
		Console.WriteLine("Mean: " + Mean(numbers));
		Console.WriteLine("Median: " + Median(numbers));
	}
}
