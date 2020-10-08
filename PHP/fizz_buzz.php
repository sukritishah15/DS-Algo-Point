<?php
/*
 * Problem Statement: Write a program that prints the numbers 1 to 100. However,
 * for multiples of three, print “Fizz” instead of the number. Meanwhile, for
 * multiples of five, print “Buzz” instead of the number. For numbers which are
 * multiples of both three and five, print “Algorithms.FizzBuzz”.
 *
 * Language: PHP
*/

for ($i = 1; $i <= 100; $i++) {
  if ($i%3==0 && $i%5==0){
    echo "Algorithms.FizzBuzz\n";
  }elseif ($i%3==0){
    echo "Fizz\n";
  }elseif ($i%5==0){
    echo "Buzz\n";
  }else{
    echo strval($i)."\n";
  }
}


/*
 * Input - n-hardcoded (100)
 * Time Complexity: O(n)
 * Space Complexity: constant
 * Output:
	1
	2
	Fizz
	4
	Buzz
	Fizz
	7
	8
	Fizz
	Buzz
	11
	Fizz
	13
	14
	Algorithms.FizzBuzz
	16
	17
	Fizz
	19
	Buzz
	Fizz
	22
	23
	Fizz
	Buzz
	26
	Fizz
	28
	29
	Algorithms.FizzBuzz
	31
	32
	Fizz
	34
	Buzz
	Fizz
	37
	38
	Fizz
	Buzz
	41
	Fizz
	43
	44
	Algorithms.FizzBuzz
	46
	47
	Fizz
	49
	Buzz
	Fizz
	52
	53
	Fizz
	Buzz
	56
	Fizz
	58
	59
	Algorithms.FizzBuzz
	61
	62
	Fizz
	64
	Buzz
	Fizz
	67
	68
	Fizz
	Buzz
	71
	Fizz
	73
	74
	Algorithms.FizzBuzz
	76
	77
	Fizz
	79
	Buzz
	Fizz
	82
	83
	Fizz
	Buzz
	86
	Fizz
	88
	89
	Algorithms.FizzBuzz
	91
	92
	Fizz
	94
	Buzz
	Fizz
	97
	98
	Fizz
	Buzz
*/
?>
