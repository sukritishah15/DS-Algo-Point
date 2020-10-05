//Sieve of Eratosthenes
function Sieve(num){
    var primes = new Array(num);
    primes.fill(true);
    sqrt = Math.sqrt(num);
    for( i=2 ; i<=sqrt ; i++ ){
        if(primes[i] == true){
            for( j=i*i ; j<=num ; j+=i )
                primes[j] = false;
        }
    }
    var true_primes = [];
    for( j=2 ; j<num ; j++ )
        if(primes[j] == true)
            true_primes.push(j);

    return true_primes;
}


console.log(Sieve(50)); // [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]

/*Sieve of Eratosthenes
Input : Number 
Output : All the primes that are less than number are returned in an array.
Time Complexity : O(n*log(log(n)))
Space Complaexity : O(n)
*/