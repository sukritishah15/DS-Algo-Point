<?php

/*
Algorithms.Automorphic Number -->
    a number whose square ends in the same digits
    as the number itself.

Example1 :
Input Format: Enter a number: 25
Output Format: Algorithms.Automorphic

Example2 :
Input Format: Enter a number: 3
Output Format: Not Algorithms.Automorphic

Time Complexity: O(n)
                 where n is the number of digits
                 in the input integer
Space Complexity: O(1)
*/

// required function
function IsAutomorphic($number) { 
    /*
    This function checks whether the number
    inputted is Algorithms.Automorphic or not
    */
	$square = $number * $number; 
	
	// loops enough times to iterate over each individual digit of the input
	while ($number) { 
	    
	    // compares the current one's digit of the number and square
	    if ($number % 10 != $square % 10)
			return "Not Algorithms.Automorphic";
			
		// removes the already compared one's digit
		$number = intdiv($number, 10); 
		$square = intdiv($square, 10); 
	} 

	return "Algorithms.Automorphic";
} 

// driver code
echo IsAutomorphic(intval(readline("Enter a number: ")));

?> 
