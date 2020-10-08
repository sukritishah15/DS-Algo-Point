<?php # euclid_gcd.php - Nate Nasteff

/*
** The Euclidian Algorithm for getting the greatest common divisor of two
** integers operates by performing modulo operation (b % a) recursivley (which
** then turns to a % b) until the the result of the modulo operation reaches 0.
** This function takes two int args and returns an int (GCD)
*/

$get_gcd = function ($int_a, $int_b) use (&$get_gcd) {
  return ($int_a == 0) ? $int_b : $get_gcd($int_b % $int_a, $int_a);
};

// DataStructures.Test Case

$int_a = 325;
$int_b = 5;

echo "\nYour numbers:\n" . $int_a . " " . $int_b
  . "\n\nGreatest common divisor:\n" . $get_gcd($int_a, $int_b)
  . "\n";

/*
** Sample I/O
**
** INPUT:
** 
** 
**
** OUTPUT:
**
** Greatest common divisor of 111 and 9: 3
**
**
** Time complexity - O(log(a + b))
**
** Space complexity - O(1)
**
 */