using System;


public class countingSort
{
    public static void countingSort_letters(char [] letters)
    {
        int letters_length = letters.Length;
        
        //For Storing Sorted Characters  
        char[] printed = new char[letters_length];

        
        //Store count of each individual character
        int[] count = new int[256];

        for (int n = 0; n < 256; ++n)
            count[n] = 0;

        //Store count of each character 
        for (int n = 0; n < letters_length; ++n)
            ++count[letters[n]];

        
        //Store actual position of characters 
        for (int n = 1; n <= 255; ++n)
            count[n] += count[n - 1];

        /*Build the output character array 
          To make it stable we are operating in reverse order. */ 
        for (int n = letters_length - 1; n >= 0; n--)
        {
            printed[count[letters[n]] - 1] = letters[n];
            --count[letters[n]];
        }
 
       //Store Sorted characters 
        for (int n = 0; n < letters_length; ++n)
            letters[n] = printed[n];

        Console.Write("Sorted Characters: ");
        for (int n = 0; n < letters.Length; ++n)
            Console.Write(letters[n] + " , ");
    }

    public static void countingSort_integers(int[] integers)
    {
        //Store Sorted Integers
        int[] printed = new int[integers.Length];

        int lowest_integer = integers[0];
        int highest_integer = integers[0];

        for(int n = 1; n < integers.Length; n++)
        {   
            /*Compare each integer to the last lowest integer
              Assign as lowest if lower than the last*/
            if(integers[n] < lowest_integer) lowest_integer = integers[n];

            /*Compare each integer to the last highest integer
              Assign as highest if higher than the last*/
            else if (integers[n] > highest_integer) highest_integer = integers[n];
        }

        //initialize count frequency
        int[] counts = new int[highest_integer - lowest_integer + 1];

        //initialize the individual frequencies
        for (int n = 0; n < integers.Length; n++)
        {
            counts[integers[n] - lowest_integer]++;
        }

        //recount
        counts[0]--;
        for (int n = 1; n < counts.Length; n++)
        {
            counts[n] = counts[n] + counts[n - 1];
        }

        //Sort the integers
        for (int n = integers.Length - 1; n >= 0; n--)
        {
            printed[counts[integers[n] - lowest_integer]--] = integers[n];
        }

        //Display Sorted Integers
        Console.WriteLine("\n" + "Sorted Integers: ");
        foreach (int integer in printed)
            Console.Write(integer + " , ");
        
        Console.WriteLine();
    }


    //Testing the Counting Sort functions
    public static void Main()
    {
        Console.WriteLine("Welcome! to the Count Sort Algorithm \n");
        Console.WriteLine(@"What would you be sorting today?
for characters, input 1 
for integers, input 2 ");
        Console.WriteLine();

        int choice = Convert.ToInt32(Console.ReadLine());

        //Test Counting Sort for Characters
        if (choice == 1) 
        {
            Console.Write("Input Characters: ");
            char[] letters = Console.ReadLine().ToCharArray();

            countingSort_letters(letters);
        }

        //Test counting Sort for Integers
        if(choice == 2){
            Console.WriteLine("How many Integers? ");
            int integer_count = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Input Integers: ");
            int[] integers = new int[integer_count];
            for(int n = 0; n < integer_count; n++)
            {
                integers[n] = Convert.ToInt32(Console.ReadLine());
            }

            countingSort_integers(integers);
        }

        Console.ReadLine();
    }
}

/*  
    countingSort_letters   
    Sample INPUT
    Input Characters: abtfrq

    Sample OUTPUT
    Sorted Characters: a , b , f , q , r , t ,
    
    countingSort_integers
    Sample INPUT
    Input Integers: 
    3
    10
    -2
    0
    -12

    Sample OUTPUT
    Sorted Integers:
    -12 , -2 , 0 , 3 , 10 ,

    Time Complexity: O(n+k) 
                     where n is the number of elements from input and k is the range of input.
    Space Complexity: O(n+k) 

 */
