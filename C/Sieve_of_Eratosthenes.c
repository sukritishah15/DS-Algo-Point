#include <stdio.h>
#include <stdlib.h>

void seive_of_era(int n){
    long long i,j;
    int *primes;
    primes = malloc(sizeof(int) * (n+1));
    for (i = 2;i<n+1; i++){
        primes[i] = 1;
    }

    for (i = 2;i <n+1; i++){
        if (primes[i]){
            for (j=i;i*j<n+1; j++){
                primes[i * j] = 0;
            }
        }
    }
    printf("Prime number less than or equal to are: \n");
    for (i=2;i<n+1;i++){
        if (primes[i]){
            printf("%d ", i);
        }
    }
}
int main(void) {
	int n;
	printf("Enter the Number: ");
	scanf("%d",&n);
	seive_of_era(n);
	return 0;
}

/* 
The Sieve of Eratosthenes algorithm takes O(N log (log N)) time
to find all prime numbers less than N time complexity.
Space Complexity: O(1)

 Input and Output Cases:

 Enter the Number: 20
 Prime number less than or equal to are:
 2 3 5 7 11 13 17 19

 Enter the Number: 30
 Prime number less than or equal to are:
 2 3 5 7 11 13 17 19 23 29

 */
