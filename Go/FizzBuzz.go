package main

import "fmt"

func fizzbuzz() {
	for i:=1; i<=100;i++ {
		if i%3==0{
			fmt.Println("Buzz")
		} else {
			fmt.Println(i)
		}
	}
}

func main() {
	fizzbuzz();
}

/*
Output:
1
2
Buzz
4
5
Buzz
7
8
......
and so on.

Time complexity = O(1)
Space complexity = O(1)
*/
