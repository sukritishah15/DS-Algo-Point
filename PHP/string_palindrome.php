<?php # string_palindrome.php - Nate Nasteff 2020

/*
** A very simple set of functions, one that returns a boolean 
** after comparing the original string to the reversed string,
** and another function which takes said boolean as arg and
** tells the user if the word is a palindrome or not.
*/

$palindrome = function ($str) {
  echo "You entered: " . $str;
  $str = strtolower($str);
  return strrev($str) == $str ?
    true : false;
};

$is_palindrome = function ($bool) {
  return ($bool) ?
    "\nThis word is a palindrome.\n\n" : "\nThis word is not a palindrome.\n\n";
};

$str = "Milk";
$str2 = "Racecar";

echo $is_palindrome($palindrome($str));
echo $is_palindrome($palindrome($str2));


/*
**
** Sample I/O
**
** INPUT: "Milk" "Racecar"
**
** Output:
** 
** You entered: Milk
** This word is not a palindrome.
**
** You entered: Racecar
** This word is a palindrome.
**
**
** Time complexity: O(n)
** Space complexity: O(1)
**
*/