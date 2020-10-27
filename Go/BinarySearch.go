package main

import (
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
)

// Implementation of binary search without using recursion
func search(array []int, elementToFind int) int {
	low := 0
	high := len(array) - 1

	for low <= high {
		// Find the middle index of array
		index := int((low + high) >> 1)

		// If find the element, return the position
		if array[index] == elementToFind {
			return index
		} else if array[index] < elementToFind {
			// The target value is on the upper portion of the array
			low = index + 1
		} else {
			// The target value is on the lower portion of the array
			high = index - 1
		}
	}

	// The searched item was not found
	return -1
}

func main() {
	var array []int
	var elementToFind int

	// Converts all input arguments to integers and adds them to the list to be sorted
	for _, value := range os.Args[1:] {
		number, err := strconv.Atoi(value)

		if err != nil {
			log.Fatal(err)
		}

		array = append(array, number)
	}

	// Sort array of ints in increasing order
	sort.Ints(array)

	// Asks the user to enter the number they want to find within the array
	fmt.Print("Enter the number to find: ")
	fmt.Scanf("%d", &elementToFind)

	fmt.Println(fmt.Sprintf("Element %d was found at position %d", elementToFind, search(array, elementToFind)))
}

/*
I => Array: 12 19 20 33 44 68 79 80
	 Element to find: 68
O => 5

Time complexity: O(log n)
Space complexity: O(1)
*/
