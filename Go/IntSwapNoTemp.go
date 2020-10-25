package main

import "fmt"

func main(){
	var x,y int
	fmt.Println("This program swaps two integers without using a temp variable.")
	fmt.Println("Enter integer x : ")
	fmt.Scanln(&x)
	fmt.Println("Enter integer y : ")
	fmt.Scanln(&y)
	fmt.Printf("x is %d, y is %d\n",x,y)
	swapInt(&x,&y) // change this to swapIntXor if you want to try out swaping via xor functions
	fmt.Printf("x is %d, y is %d\n",x,y)
}


//I'm using pointers just so that the pointers point to the correct integer after this function ends.
func swapInt(x *int, y *int){
	fmt.Println("Swapping x and y...")
	*x = *x + *y //x = x + y
	*y = *x - *y //y = x + y - y = x
	*x = *x - *y //x = x + y - x = y
}


//A function that does the same thing but with the xor function.
func swapIntXor(x *int, y *int){
	fmt.Println("Swapping x and y with xor...")
	*x = *x^*y // x = x xor y
	*y = *x^*y //y = x xor y xor y = x
	*x = *x^*y // x = x xor y xor x = y
}

/*
I/O =>
This program swaps two integers without using a temp variable.
Enter integer x :
18
Enter integer y : 
-32
x is 18, y is -32
Swapping x and y...
x is -32, y is 18

Time complexity: O(1)
Space complexity: O(1)
*/