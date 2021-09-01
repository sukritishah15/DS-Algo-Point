
//JAVA Code for Merging 2 Sorted Arrays

import java.util.Scanner;

public class Merge2Arrays
{
	
	public static void mergeArrays(int[] ary1, int[] ary2, int capacity1,
								int capacity2, int[] ary3)
	{
		
		int a = 0, b = 0, c = 0;
	
		// Traverse both array
		while (a<capacity1 && b <capacity2)
		{
			//if first element of first array is smaaller than 2nd element, 
            //then keep as it and increment first array else store in C
			if (ary1[a] < ary2[b])
				ary3[c++] = ary1[a++];
			else
				ary3[c++] = ary2[b++];
		}
	
		// Assign remaining elements1 of second array if remain at last
		while (a < capacity1)
			ary3[c++] = ary1[a++];
	
		// Assign remaining elements1 of second array if remain at last
		while (b < capacity2)
			ary3[c++] = ary2[b++];
	}
	
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);  
		
		int elements1;
		
		System.out.print("Enter the number of elements1 you want to store: ");  
		elements1=sc.nextInt();
		int[] ary1 = new int[elements1];  

		System.out.println("Enter your 1st Sorted Array ");
		
		for(int a=0; a<elements1; a++)  
		{  
	    //taking 1st arrayuser input
		ary1[a]=sc.nextInt();  
		}  
		
		int elements2;
		System.out.print("Enter the number of elements1 you want to store in 2 nd array ");  
		elements2=sc.nextInt();
  
		int[] ary2 = new int[elements2]; 
		System.out.println("Enter your 2nd Sorted Array ");
		
		for(int a=0; a<elements2; a++)  
		{  
            //taking 2 nd array from user
		ary2[a]=sc.nextInt();  
		}  
		

	
		int[] ary3 = new int[elements1+elements2];

        //function call
		mergeArrays(ary1, ary2, elements1, elements2, ary3);
	
		System.out.println("After merging Array1 and Array2 both");
		for (int a=0; a < elements1+elements2; a++)
			System.out.print(ary3[a] + " ");
	}
}

/*
Sample INPUT and OUTPUT:

Enter the number of elements1 you want to store: 4
Enter your 1st Sorted Array 
7 9 11 13

Enter the number of elements1 you want to store in 2 nd array 4
Enter your 2nd Sorted Array 
10 12 14 16

After merging Array1 and Array2 both
7 9 10 11 12 13 14 16

    Input : Two Sorted Arrays
	Output: Merging Both the arrays
	Algorithm: JAVA code to merge 2 sorted arrays

    
    Time Complexity: O(n)
    Space Complexity: O(n)

*/