#include<stdio.h>
int MaxNum(int num) 
{ 
    // hashed array to store count of digits 
    int count[]={0,0,0,0,0,0,0,0,0,0}, b=0, multiplier=1; 
    while(num>0){   //Counting each how many times each digit occurs
        count[num%10]+=1;
        num/=10;
    }
    for(int i=0; i<=9; i++) //Forming thelargest digit
        while(count[i]>0){ 
            b+=(i*multiplier); 
            count[i]--; 
            multiplier*=10; 
        }
    return b; 
} 
      
int main(){
    int num; 
    printf("Enter number: ");
    scanf("%d", &num);
    printf("%d", MaxNum(num)); 
    return 0;
}

/*
    Input:-
    Enter Number: 38293367
    Output:-
    98763332
    Time Complexity: O(NlogN), for N digit number
    Space Complexity: O(N), for N digit number
*/