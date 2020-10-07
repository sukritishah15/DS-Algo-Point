using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CollatzSequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a number to see the Collatz Sequence");
            int startingNum = Convert.ToInt32(Console.ReadLine());

            while (startingNum != 1)
            {
                Console.Write(startingNum + " ");

               
                if ((startingNum & 1) == 1)
                    startingNum = 3 * startingNum + 1;

                
                else
                    startingNum = startingNum / 2;
            }

           
            Console.Write(startingNum);

            Console.ReadLine();
        } 

           

       
        
        
    }
}
