function gcd_two_numbers(x, y) {
    if(x===0) return y ; 
    if(y===0) return x ; 

    if(x===y) return x; 
    if(x > y) 
    return gcd_two_numbers(x-y , y) ; 
    else return gcd_two_numbers(x, y-x);  
  
}
  console.log(gcd_two_numbers(2, 10));
 

