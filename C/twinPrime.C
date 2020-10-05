
#include<stdio.h> 
int check_prime(int n)
{
    if(n == 1)
    {
        return 0;
    }

    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
       
            return 0;
        }
    }

   
    return 1;
}

int main(void)
{   

    int start, end;

    printf("Enter start: ");
    scanf("%d", &start);

    printf("Enter end: ");
    scanf("%d", &end);

    for(int i = start; i < end-1; i++)
    {
        if(check_prime(i) && check_prime(i + 2))
        {            
            printf("{%d, %d}\n", i, i + 2);
            
        }                
    }    

    return 0; 
}

/*
Enter start: 1
Enter end: 50
{3, 5}
{5, 7}
{11, 13}
{17, 19}
{29, 31}
{41, 43}

time complexity- O(n^2)
space complexity- O(1)
*/

