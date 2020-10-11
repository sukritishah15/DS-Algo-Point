package Java.Algorithms;

import java.util.Scanner;

public class FibonnaciNumbers {
	
	public int getFibonnaciNumber(int index) {
		int fibonnaciValue = -1;
		int a = 0, b = 1;
		if(index < 2)
			return index;
		
		for(int i = 2; i < index; i ++) {
			fibonnaciValue = a + b;
			a = b;
			b = fibonnaciValue;
		}
		return fibonnaciValue;
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter the index 'n' to fetch the Fibonnaci Number");
		int index = scn.nextInt();
		
		if(index < 0) {
			System.out.println("Invalid index: "+index+" entered to fetch value from the Fibonnaci Series");
			return;
		} 
		int fibonnaciValue = new FibonnaciNumbers().getFibonnaciNumber(index);
		if(fibonnaciValue != -1)
			System.out.println("Fibonnaci Value at index "+ index +" is " + fibonnaciValue);

	}

}

/*
Sample Input & Output

Input1: 
Enter the index 'n' to fetch the Fibonnaci Number
5

Output1:
Fibonnaci Value at index 5 is 3

Input2:
Enter the index 'n' to fetch the Fibonnaci Number
-2

Output2:
Invalid index: -2 entered to fetch value from the Fibonnaci Series

Time Complexity:O(n)
Space Complexity:O(1)
*/

