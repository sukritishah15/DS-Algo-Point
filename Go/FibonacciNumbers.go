package main

import "fmt"

func fibonacciSum(n int) int{
	//Handle cases for n = 1 and n=2
	if n==1 {
		return 1;
	}
	if n==2 {
		return 2;
	}

	//initiate first two values
	a := 1
	b := 1
	//inititate suma and adjust n accordingly
	sum := 2
	n-=2

	//get sum for n values in fibonacci series
	for n!=0{
		a,b = b,a+b
		sum+=b
		n--
	}
	return sum
}

func main(){
//Read value of n
 fmt.Println("Enter value of 'n'(integer):")
 var n int
 _,err := fmt.Scanf("%d",&n);
 if err!=nil{
 	fmt.Println("Invalid input")
 	return
 }
 fmt.Printf("Sum till nth term:%d",fibonacciSum(n))
}

/*
I/O =>
Enter value of 'n'(integer):
4
Sum till nth term:7

Time complexity: O(n)
Space complexity: O(1)
*/