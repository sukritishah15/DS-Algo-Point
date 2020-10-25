package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

func prefixSum(array []int) []int {
	// Start from 1 because the first position not change
	for i := 1; i < len(array); i++ {
		// Adding present element with previous element
		array[i] = array[i] + array[i-1]
	}
	return array
}

func main() {
	var array []int

	// Converts all input arguments to integers and adds them to the list
	for _, value := range os.Args[1:] {
		number, err := strconv.Atoi(value)

		if err != nil {
			log.Fatal(err)
		}

		array = append(array, number)
	}

	fmt.Println("Input array => ", array)
	fmt.Println("Output array => ", prefixSum(array))
}

/*
I => 2 5 -2 12 55
O => 2 7 5 17 -38


Time complexity: O(n)
Space complexity: O(n)
*/
