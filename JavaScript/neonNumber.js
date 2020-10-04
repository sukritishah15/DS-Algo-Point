//Checks whether a number is NEON or not 
function checkIfNeon(num){
    sqr = num*num ;
    sum = 0;
    while(sqr>0){
        sum += sqr % 10;
        sqr = parseInt(sqr/10);
    }
    console.log(sum);
    if(sum == num)return true;
    else return false;
}

console.log(checkIfNeon(9)); // true
console.log(checkIfNeon(12)); //false

/*
Input : Number
Output : true if number is NEON number, else returns false 
*/