package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

func sort(array []int) []int {
	arrayLen := len(array)

	for i := 0; i < arrayLen-1; i++ {
		for j := 0; j < arrayLen-i-1; j++ {
			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}

	return array
}

func main() {
	array := []int{}

	for _, value := range os.Args[1:] {
		number, err := strconv.Atoi(value)

		if err != nil {
			log.Fatal(err)
		}

		array = append(array, number)
	}

	fmt.Println("Unsorted array => ", array)
	fmt.Println("Sorted array => ", sort(array))
}

/*
I => -2 45 0 11 -9 3 92 88234 8 -14234 234 215 52
O => -14234 -9 -2 0 3 8 11 45 52 92 215 234 88234

Time complexity: O(n^2)
Space complexity: O(1)
*/
