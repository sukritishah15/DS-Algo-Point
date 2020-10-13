package main

import (
	"fmt"
	"math"
)

func main() {
	// Input int array
	array := []int{3, 82713871, 42, -123142, 35, 2, 12, -3, -4, -1, 3}
	sortedArray := CountingSort(array)
	fmt.Println(sortedArray)
}

/* 
Implements Counting Sort on []int and returns sorted []int
Input: []int 	eg: [3 82713871 42 -123142 35 2 12 -3 -4 -1 3]
Output: []int 	eg: [-123142 -4 -3 -1 2 3 3 12 35 42 82713871]
Time Complexity: O(n + k) where n is the number of elements in array and k is the range of input
Space Complexity: O(n + k) Auxilary array
*/
func CountingSort(arr []int) []int {
	/*
	Usual approach for implementing Counting Sort would be to directly use index
	from 0 to max element in the array but it fails while dealing with negative numbers.
	Therefore, what we do here is that we take min and max of the given array and map them
	to the array of index starting from 0 to min + max
	*/

	min := math.MaxInt64
	max := math.MinInt64
	
	// Find min and max
	for _, v := range arr {
		if min > v {
			min = v
		}
		if max < v {
			max = v
		}
	}

	// Initialze array to store counts
	count := make([]int, max - min + 1)

	for _, x := range arr {
		count[x-min]++
	}

	sortedArray := make([]int, len(arr))

	i := 0
	for k, v := range count {
		// Insert all v occurences of element k in empty array
		for v > 0 {
			sortedArray[i] = k + min
			v--
			i++
		}
	}

	return sortedArray
}