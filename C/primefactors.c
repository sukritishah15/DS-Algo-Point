#include <stdio.h>
#include <stdlib.h>
 

 
int main(){
    unsigned long long int i,j;
    int *primes;
    int z = 1;
    int limit =0;
    
    scnf("%d",&limit); 
 
    primes = malloc(sizeof(int) * limit);
 
    for (i = 2;i < limit; i++)
        primes[i] = 1;
 
    for (i = 2;i < limit; i++)
        if (primes[i])
            for (j = i;i * j < limit; j++)
                primes[i * j] = 0;
 
    printf("\nPrime numbers are: \n");
    for (i = 2;i < limit; i++)
        if (primes[i])
            printf("%d ", i);
 
return 0;
}
/*
Time Complexity :O(logN)

Space Complexity :O(N)

Input : 10

Output : Prime numbers are: 2 3 5 7

*/
