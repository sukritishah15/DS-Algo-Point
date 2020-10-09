<?php # max_number.php - Nate Nasteff 2020

/*
** This function will take an integer argument and
** rearrange the digits to produce the highest possible
** number. Once split into a string array, the numbers are sorted,
** then iterated over, adding each value multiplied by the digit's
** poisition left of the decimal point.
** IE (int=417 => sorted_arr=[1,4,7] => 1*1 + 4*10 + 7*100 = 741)
*/

$max_number = function ($num) {
  $max = 0;
  $multi = 1;
  $arr = array_map('intval', str_split($num));
  sort($arr);
  for ($i = 0; $i < count($arr); $i++) {
    // This prevents int out of bounds
    if (count($arr) > 9)
      return "Number too big!";
    $max += $arr[$i] * $multi;
    $multi *= 10;
  }
  return $max;
};

$int = 256783441;
echo "\nOriginal number:\n$int\n\nMax number:\n"
  . $max_number($int) . "\n";


/*
** Example I/O
**
** INPUT:
** 256783441
**
** OUTPUT:
**
** Original number:
** 256783441
**
** Max number:
** 87654432 
** 
** Time complexity: O(n)
** Space complexity: O(1)
** 
*/