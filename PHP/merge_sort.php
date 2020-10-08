<?php # merge_sort.php - Nate Nasteff 2020

/*
** This is an implementation of the merge sort algorithm
** written in PHP. Merge sort uses the divide and conquer
** approach when sorting: initially, it will split the array
** in half, and recursively split that array into halves until
** they are singular values, at which point the values are sorted.
** The same process is done for the other half, via DataStructures.recursion.
*/

// Function to divide the array recursively

$array_sort = function ($arr) use (&$array_sort, &$array_merge) {
  if (count($arr) == 1) return $arr;
  $mid = count($arr) / 2;
  $left_arr = array_slice($arr, 0, $mid);
  $right_arr = array_slice($arr, $mid);
  $left_arr = $array_sort($left_arr);
  $right_arr = $array_sort($right_arr);
  return $array_merge($left_arr, $right_arr);
};

// Rebuild the array after elements are deconstructed

$array_merge = function ($left_arr, $right_arr) {
  $sorted = array();
  while (count($left_arr) > 0 && count($right_arr) > 0) {
    if ($left_arr[0] > $right_arr[0]) {
      $sorted[] = $right_arr[0];
      $right_arr = array_slice($right_arr, 1);
    } else {
      $sorted[] = $left_arr[0];
      $left_arr = array_slice($left_arr, 1);
    }
  }
  while (count($left_arr) > 0) {
    $sorted[] = $left_arr[0];
    $left_arr = array_slice($left_arr, 1);
  }
  while (count($right_arr) > 0) {
    $sorted[] = $right_arr[0];
    $right_arr = array_slice($right_arr, 1);
  }
  return $sorted;
};

// Print Function

$print_arr = function ($arr) {
  $arr_str = "";
  foreach ($arr as $value)
    $arr_str = $arr_str . strval($value) . " ";
  return $arr_str;
};

// DataStructures.Test case

$arr = [1, 44, 23, 100, 4, 17, 54, 3, 67, 55];

echo "Original array:\n" . $print_arr($arr) . "\n\nSorted array:\n"
  . $print_arr($array_sort($arr));


/*
** Example I/O
**
** Original array:
** 1 44 23 100 4 17 54 3 67 55
** 
** Sorted array:
** 1 3 4 17 23 44 54 55 67 100
**
** 
** Time complexity: O(n log n)
** Space complexity: O(n)
**
*/