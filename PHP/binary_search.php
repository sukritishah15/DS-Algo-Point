<?php
/*
*Binary Search is a searching technique used to search an element in a Sorted array.
*Binary search works with only sorted array.

* Sample I/O
Example1:
 Input: key=10
 Output: 10 key is Exist.

Example2:
 Input: key=17
 Output: 17 key Does not Exist.

 Time Complexity of binary search : O(log n)
 Space Complexity of binary search : O(1)

*/

function binarySearch($array, $key) {
  // check for an empty array
  if (count($array) === 0) return false;
  $low = 0;
  $high = count($array) - 1;

  while ($low <= $high) {
    // compute middle index
    $midpoint = floor(($low + $high) / 2);

    if ($key < $array[$midpoint]) {
      // The key value is less than the midpoint value.
      $high = $midpoint - 1;
    } elseif ($key > $array[$midpoint]) {
      // The key value is greater than the midpoint value.
      $low = $midpoint + 1;
    } else {
        // This is the key we are looking for.
        return $midpoint;
    }
  }
  // The key was not found.
  return false;
}

// Sorted array
$array = array(1, 2, 4, 10, 15, 18, 22);
$key = 4;
if(binarySearch($array, $key) == true) {
    echo $key." key is Exist.";
}
else {
    echo $key." key Does not Exist.";
}
?>
