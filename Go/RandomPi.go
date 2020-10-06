package main

import (
	"fmt"
	"math/rand"
	)
	
func main(){
	var inside, outside, x, y float64
	ITER := 10000000
	for i:=0; i <= ITER; i++ {
		x = rand.Float64()
		y = rand.Float64()
		if x*x + y*y <= 1{
			inside++
		}
		outside++
	}
	pi := 4.0 * (inside / outside)
	fmt.Println(pi)
}

/*
* INPUT: NONE
* OUTPUT: APPROXIMATE VALUE OF PI(3.141)
* TIME COMPLEXITY: O(ITER)
* SPACE COMPLEXITY : O[1)
* DEMO: https://play.golang.org/p/cZzhLi3ZPEj
*/
