#include<stdio.h>

int main()
{
    int a1,a2,n;                        //a1,a2 are the first two elements of AP
    int nterm;                          //nterm is the nth term of the AP
    int d;                              //d is the common difference between any two consecutive terms of an AP
   
    printf("Enter the value for a1");
    scanf("%d",&a1);

    printf("Enter the value for a2");
    scanf("%d",&a2);

    printf("enter n for nth term of an AP");
    scanf("%d",&n);

    d=a2-a1;                            //difference between two terms

    nterm=a1+(n-1)*d;                   //nth term of AP 

    printf("nth term of the AP is = %d",nterm);

    /*

    Problem name :- Finding the nth term of an AP

    For example:-

    Input:- 2 4 7
    Output:- 14

    Input:- 1 5 1
    Output:- 1

    Input:- 14 28 5
    Output:- 70

    Time Complexity:- O(1)
    Space Complexity:- O(1)
    
    */



}