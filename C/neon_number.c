/*Program to check wether a given number is neon number or not 

A neon number is a number where the sum of digits of square of the number is equal to the number.
Example: 9
Sum of digits of it's square = (8 + 1) = 9 = number entered by the user
So, 9 is a NEON NUMBER.

the soluion is to :
1)square the entered number n. (square=n*n)
3)to calculate the sum of digits in the square of the number,
 In a loop with condition (s>0) we do the following operations:
    i)  digit = s%10; -- this will take the right most digit from the square of number
    ii) sum=sum+d; -- we add the digit to 'sum' for calculating the sum of all digits of suqare. 
    iii)s=s/10; --this will drop the rightmost digit.
    iv) as the loop goes on it will sum up all the digits form the suquare of number
4) now we compare n with sum that we calculated:
    i) if n is equal to sum then it is a neon number 
    ii)else it is not a neon number*/

#include <stdio.h>


int main(void) {
	int n , sum, digit, square;
	printf("enter the number you want to check: \n");
	scanf("%d",&n); //take input n
	square=n*n; //square the number.
	sum=0; //initialise sum with 0.
	
	while(square > 0) {
	    digit = square%10; //this will take the right most digit from the square of number
	    sum = sum + digit; //we add the digit to 'sum' for calculating the sum of all digits of suqare.
	    square = square / 10; //this will drop the rightmost digit.
	    
	}
	
	if(sum == n) {
	    printf("%d IS A NEON NUMBER",n);
	}
	
	else {
	    printf("%d is NOT a NEON NUMBER ",n);
	}
	
	return 0;
}

/*

Time complexity - O(1)
Space complexity - O(1)

I/O 1 :-

enter the number you want to check:                                                                                                     
9                                                                                                                                       
9 IS A NEON NUMBER

I/O 2 :-

enter the number you want to check:                                                                                                     
12                                                                                                                                      
12 is NOT a NEON NUMBER
    
*/