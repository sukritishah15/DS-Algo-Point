using System;  
                      
public class RotateLeft  
{  
    public static void Main()  
    {  
        //Initialize array   
        int [] arr = new int [] {1, 2, 3, 4, 5};   
        //n determine the number of times an array should be rotated  
        int n = 3;  
          
       //Rotate the given array by n times toward left  
        for(int i = 0; i < n; i++){  
            int j, first;  
            //Stores the first element of the array  
            first = arr[0];  
          
            for(j = 0; j < arr.Length-1; j++){  
                //Shift element of array by one  
                arr[j] = arr[j+1];  
            }  
            //First element of array will be added to the end  
            arr[j] = first;  
        }  
          
        Console.WriteLine();  
          
        //Displays resulting array after rotation  
        Console.WriteLine("Array after left rotation: ");  
        for(int i = 0; i< arr.Length; i++){  
            Console.Write(arr[i] + " ");  
        }  
    }  
} 

/*
Array after left rotation: 
4 5 1 2 3 

time complexity: O(2^n)
space complexity: O(n)
*/
