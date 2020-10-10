using System;


public class Power_Set
{
    // C# program for generating power set of a given set 
    public static void Generatepower_set(string set)
	{

        //derive cardinality of set from string length
        int set_size = set.Length;

        //Calculate number of subsets: 2**set_size
        uint pow_set_size = (uint)Math.Pow(2, set_size);
        int counter, n;

        //an empty set is a subset of every set
        Console.Write("NULL");

        //Generate non-empty subsets
        for (counter = 0; counter < pow_set_size; counter++)
        {   
            //elements of non-empty subsets
            for (n = 0; n < set_size; n++)
            {
                /* Check if nth bit in the counter is set. 
                If set then print nth element from set */
                if ((counter & (1 << n)) > 0)
                    Console.Write(set[n]);
            }

            //display each subset on a new line
            Console.WriteLine();
        }
    }

    //testing Generatepower_set
    public static void Main()
    {   
        Console.Write("C# program for generating power set of a given set \n");
           
        Console.Write(@"
        NOTE!! 
                                
        Input elements of Set (as a string) 
        For Example: {1, 2, 3} 
        as a String is 123

Input elements of Set: ");

        //static input
        string set = Console.ReadLine();

        //calling the function
        Generatepower_set(set);
            
        Console.ReadLine();
    }

}

/* Sample INPUT
   Generate power set of {1, a, 2, 3}
   as a String: 1a23

   Sample OUTPUT
   NULL
   1
   a
   1a
   2
   12
   a2
   1a2
   3
   13
   a3
   1a3
   23
   123
   a23
   1a23

   Time Complexity:

   Inside the function:

   //derive cardinality of set from string length
        int set_size = set.Length;       -----------------------O(1) 

        //Calculate number of subsets: 2**set_size
        uint pow_set_size = (uint)Math.Pow(2, set_size);  ------O(n)
        int counter, n;

        //an empty set is a subset of every set
        Console.Write("NULL");

        //Generate non-empty subsets
        for (counter = 0; counter < pow_set_size; counter++) ----O(n2^n)
        {   
            //elements of non-empty subsets
            for (n = 0; n < set_size; n++)  ---------------------O(n)
            {
                /* Check if nth bit in the counter is set. 
                If set then print nth element from set /
                if ((counter & (1 << n)) > 0)           --------O(1)
                    Console.Write(set[n]);
            }

            //display each subset on a new line
            Console.WriteLine();
        }

    total time = O(1) + O(n) + O(n2^n)  =  O(n2^n)
    
    Space Complexity: O(n2^n)
*/