#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main()
{
    int no, sqr, temp, last;
    int n =0;
 
    printf("Enter a number \n");
    scanf("%d",&no);
 
    sqr = no*no;  //calculating square of num
    temp = no;
 
    //Counting number of digits
    while(temp>0){
        n++;
        temp = temp/10;
    }
 
    //Extracting last n digits
    int ten = floor(pow(10,n));
    last = sqr % ten;
 
    if(last == no)
        printf("Automorphic number \n");
    else
        printf("Not Automorphic \n");
 
    return 0;
}
/*
I/O Format
Enter a number
76
Automorphic number

Complexity

Time complexity: O(log n)
Space complexity: O(1)

*/