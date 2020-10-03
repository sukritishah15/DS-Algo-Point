import java.util.Scanner;
 
public class FizzBuzz {
 
	public static void main(String[] args) {
 
		int n = 100;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 && i % 5 == 0) { //multiple of 3 & 5
				System.out.print("FizzBuzz");
			} else if (i % 3 == 0) { //multiple of 3
				System.out.print("Fizz");
			} else if (i % 5 == 0) { //multiple of 5
				System.out.print("Buzz");
			} else {
				System.out.print(i);
			}
			System.out.print(" ");
		}
	}
}
