<?php 

function printTwinPrime($n) 
{ 
    $prime = array_fill(0, $n + 1, true); 
  
    for ($p = 2; $p * $p <= $n; $p++) 
    { 
          
        if ($prime[$p] == true)  
        { 
              
            for ($i = $p * 2;  
                 $i <= $n; $i += $p) 
                $prime[$i] = false; 
        } 
    } 
  
    for ($p = 2; $p <= $n - 2; $p++) 
        if ($prime[$p] &&  
            $prime[$p + 2]) 
            echo "(". $p . ", " .  
                  ($p + 2). ")" ; 
} 
  
$n = 25; 
  
printTwinPrime($n); 
  
?>

/*
Example : 
Input -- 25
Output -- (3, 5)(5, 7)(11, 13)(17, 19)

Time complexity - O(n*sqrt(n))
Space complexity - O(n)
*/
