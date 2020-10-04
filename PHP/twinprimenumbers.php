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
