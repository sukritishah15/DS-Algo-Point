<?php # mean_median.php - N. Nasteff 2020

/* The below functions are used to calculate the
** mean (sum of numbers / 2) and the median (middle
** element of a sorted set of numbers) from any given
** array of integers. The mean is shown in full to the
** 12th decimal point.
*/

// Mean

$mean = function ($arr) {
  return array_sum($arr) / count($arr);
};

// Median function

$median = function ($arr) {
  sort($arr);
  $count = count($arr);
  $middle = floor(($count - 1) / 2);
  if ($count % 2) {
    return $arr[$middle];
  } else return ($arr[$middle] + $arr[$middle + 1]) / 2;
};

// Print function

$print_arr = function ($arr) {
  $arr_str = "";
  foreach ($arr as $value)
    $arr_str = $arr_str . strval($value) . " ";

  return $arr_str;
};

// Test Case

$arr = [1, 22, 30, 8, 5, 14, 8];

echo "Original array:\n" . $print_arr($arr)
  . "\n\nMean: " . $mean($arr) . "\nMedian: " . $median($arr);

/*
** Sample I/O
**
** Original array:
** 1 22 30 8 5 14 8
**
** Mean: 12.571428571429
** Median: 8
**
**
** Time complexity: 0(n)
** Space complexity: O(1)
**
*/