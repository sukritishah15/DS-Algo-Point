#include <stdio.h>
#include <stdlib.h>
// This is one of the best algorithms to find the prime from a particular range 
// and also to find the prime number with O(nlogn) time complexity
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

