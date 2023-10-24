

function isPalindrome(num) { 
    var str = num.toString(); 
    var rev=str.split("").reverse().join(""); 
  
    if(rev == str){ 
        return true
    } 
    return false
                 
} 
  
var str1 = 1234321; 
var str2 = 112211; 
var str3 = 12345; 
  
console.log(isPalindrome(str1)); 
console.log(isPalindrome(str2)); 
console.log(isPalindrome(str3));


