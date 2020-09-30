#include<stdio.h>

int main(){
    int i, n, x, found=0; //declaration
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter %d numbers\n", n);
    for(i=0; i<n; i++)  //input elements
        scanf("%d", &ar[i]);
    printf("Enter element to be searched for: ");
    scanf("%d", &x);    
    for(i=0; i<n; i++) //searching for x
        if(ar[i]==x){   //if found
            found=1;
            printf("Element found at position %d", i+1);
            break;
        }
    if(found==0) //if not found
        printf("Element not found");        
}

/*
    Problem name :- Linear Search
    Example 1:
    Input:-
    Enter the number of elements: 5
    Enter 5 numbers
    10
    15
    35
    74
    8
    56
    Enter element to be searched for: 74

    Output:-
    Element found at position 4


    Example 2:
    Input:-
    Enter the number of elements: 5
    Enter 5 numbers
    10
    15
    35
    74
    8
    56
    Enter element to be searched for: 75
    
    Output:-
    Element not found

    
    Time Complexity:- O(n)
    Space Complexity:- O(1)
*/