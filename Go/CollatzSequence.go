package main

import (
	"fmt"
)

/**
 * The Collatz conjecture is a conjecture in mathematics that concerns a sequence defined as follows:
 * start with any positive integer n.
 * Then each term is obtained from the previous term as follows:
 * if the previous term is even, the next term is one half of the previous term.
 * If the previous term is odd, the next term is 3 times the previous term plus 1.
 * The conjecture is that no matter what value of n, the sequence will always reach 1.
 */

func collatzSequence(n int) {
	start := n
	fmt.Print(start)
	fmt.Print(" ")

	for start >= 1 {

		if start%2 == 0 {
			start = start / 2

		} else if start == 1 {

			break
		} else {
			start = 3*start + 1

		}

		fmt.Print(start)
		fmt.Print(" ")
	} 
}

func main() {
	//Read value of n
	fmt.Println("Enter value of 'n'(integer):")
	var n int
	_, err := fmt.Scanf("%d", &n)
	if err != nil {
		fmt.Println("Invalid input")
		return
	}
	// call function with the number for which we are genrating collatsz sequence.
	collatzSequence(n)

}
