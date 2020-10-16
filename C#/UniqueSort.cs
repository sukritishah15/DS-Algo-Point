using System;
using System.Collections.Generic;

public class UniqueSort
{
    public static void notRepeated(int numbersCount, int []numbers)
    {
        Dictionary<int,int> numbersSort = new Dictionary<int,int>();

        int count = 0;
        
        bool repeated = true;

        /* Sort array into dictionary */
        for (int n = 0; n < numbersCount; n++)
        {
            if (numbersSort.ContainsKey(numbers[n]))
            {
                count = numbersSort[numbers[n]];
                numbersSort[numbers[n]]++;
            }
            else
                numbersSort.Add(numbers[n], 1);
        }

        Console.WriteLine();
        Console.Write("Unique numbers: ");
        foreach (KeyValuePair<int,int> entry in numbersSort)
        {
            /* Display numbers that occur only once */ 
            if (entry.Value == 1)
                Console.Write(entry.Key + " ");
            repeated = false;
        }

        /* all numbers are repeated */
        if (repeated)
            Console.WriteLine("All numbers are repeated");
    }


    public static void notDuplicate (int numbersCount, int[] numbers)
    {
        /* Sort the array of numbers in ascending order
           then all occurrences become consecutive */ 
        Array.Sort(numbers);

        Console.WriteLine();
        Console.Write("Unique numbers: ");

        /* Traversing the sorted array of numbers */
        for (int n = 0; n < numbersCount; n++)
        {
            /* Move the index ahead while  
               there are duplicates (skip the duplicates!) */
            while (n < numbersCount - 1 && numbers[n] == numbers[n + 1])
                n++;

            /* Display last occurrence of  
               the current element (print unique numbers) */
            Console.Write(numbers[n] + " ");
        }
    
    }
    
    /* Testing the Unique number Sorting Algorithms */
    public static void Main()
    {
        Console.WriteLine("Welcome! to the Unique number Sorting Algorithm \n");        
        Console.WriteLine("For printing numbers that occur once, input 1 ");
        Console.WriteLine("For printing all unique numbers, input 2 \n");

        int choice = Convert.ToInt32(Console.ReadLine());

        Console.Write("\n How many numbers would you like to check? ");
        int numbersCount = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Input numbers: ");
        int[] numbers = new int[numbersCount];
        for (int n = 0; n < numbersCount; n++)
        {
            numbers[n] = Convert.ToInt32(Console.ReadLine());
        }

        if (choice == 1)
        {
            notRepeated(numbersCount, numbers);
        }
        if (choice == 2)
        {
            notDuplicate(numbersCount, numbers);
        }

        Console.ReadLine();

    }
}


/*  
    UniqueSort.notRepeated
    Sample INPUT
    How many numbers would you like to check? 4
    Input numbers:
    1
    2
    1
    4

    Sample OUTPUT
    Unique numbers: 2 4

    Time Complexity: O(n)
    Space Complexity: O(n)

    
    UniqueSort.notDuplicate
    Sample INPUT
    How many numbers would you like to check? 4
    Input numbers:
    1
    2
    1
    4

    Sample OUTPUT
    Unique numbers: 1 2 4

    Time Complexity: O(nlogn)
    Space Complexity: O(n)

 */
