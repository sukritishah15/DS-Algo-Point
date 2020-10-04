package main

import (
	"fmt"
	"os"
)

//Function to swap values at two positions in a slice
func swap(arr []int, i int, j int){
	t:=arr[i]
	arr[i]=arr[j]
	arr[j]=t
}

//Sorts elements in the slice as per criteria
func dutchFlag (arr []int){
	low, mid := 0, 0
	high := len(arr)-1

	for mid<=high{
		switch arr[mid]{
			case 0: swap(arr, low, mid)
				low++
				mid++
			case 1: mid++
			case 2: swap(arr, mid, high)
				high--
			default: fmt.Println("Invalid input")
			os.Exit(0)

		}
	}
}

func main(){
	fmt.Println("Enter number of elements:")
	 var n int

	 //Get number of elements
	 _,err := fmt.Scanf("%d",&n)
	 if err!=nil{
	 	fmt.Println("Invalid input")
	 	return
	 }

	 //Use a slice as number of elements is dynamic. About slices: https://tour.golang.org/moretypes/7
	 arr := make([]int, n)
	 fmt.Println("Enter values")
	 for i:= 0; i<n; i++{
	 	_,err = fmt.Scanf("%d", &arr[i])
	 	if err!=nil{
	 		fmt.Println(err)
	 		return
	 	}
	 }
	 dutchFlag(arr)
	 fmt.Println("Printing sorted flag:")
	 fmt.Println(arr)
}

/*
I/O =>
Enter number of elements:
5
Enter values
0
2
1
2
0
Printing sorted flag:
[0 0 1 2 2]

Time complexity: O(n)
Space complexity: O(1) (no extra space needed)
*/