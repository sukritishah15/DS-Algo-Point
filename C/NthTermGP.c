#include<stdio.h>
#include<math.h>

//The function returns the Nth term of a gerometric progression
int NTerm(int a, int r, int N){
    /* 
        The formula to find the Nth term of a GP is given by 
        N = a*r(N-1)
    */

   int x = (int)pow(r,N-1);
   return a*x;
}

int main(){
    /* 
        inputs : 
        a = starting number of the progression
        r = common ratio of the progression
        N = the Nth term of the progression to be found 
    */

    int a, r, N;

    printf("Enter a (starting number) : ");
    scanf("%d", &a);

    printf("Enter r (common ratio) : ");
    scanf("%d", &r);

    printf("Enter N (Nth term to find) : ");
    scanf("%d", &N);

    
    printf("The %dth term of the GP with a = %d and r = %d is %d", N, a, r, NTerm(a,r,N));

    return 0;
}

/*

Sample Input 1 : 
Enter a (starting number) : 2
Enter r (common ratio) : 2
Enter N (Nth term to find) : 4

Sample Output 1 :
The 4th term of the GP with a = 2 and r = 2 is 16.


Sample Input 2 : 
Enter a (starting number) : 2
Enter r (common ratio) : 3
Enter N (Nth term to find) : 5

Sample Output 2 :
The 5th term of the GP with a = 2 and r = 3 is 162.


Time Complexity - O(1)
Space Complexity - O(1)

*/