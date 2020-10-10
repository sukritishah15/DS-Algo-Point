package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
	"sync"
	"time"
)

func sort(value uint64, wg *sync.WaitGroup) {
	// When the execution of this function ends, the WaitGroup counter is decremented.
	// If this is not done it will result in a deadlock
	defer wg.Done()

	time.Sleep(time.Duration(value) * time.Second)
	fmt.Println(value)
}

func main() {
	// Waitgroup is used because i need to wait that all routines end before main.
	// In case the main function ends before the end of the goroutines, they will be abruptly terminated.
	var wg sync.WaitGroup

	for _, value := range os.Args[1:] {
		i, err := strconv.ParseUint(value, 10, 64)
		if err != nil {
			log.Fatal(err)
		}

		wg.Add(1)
		// Waitgroup is passed using the pointer because it must always point to it and not to a copy.
		// If a copy is used, the Done function does not decrease the counter and generates a deadlock.
		go sort(i, &wg)
	}

	// Wait until all the goroutines completes
	wg.Wait()
}

/*
I => 44 5 99 1 2 12 33
O => 1 2 5 12 33 44 99

Time complexity: O(max(input))
Space complexity: O(1)
*/
