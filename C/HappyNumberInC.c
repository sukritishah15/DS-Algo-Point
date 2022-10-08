
#include <stdio.h>    
     
//Function to check if number happy number or not    
int CheckHappyNo(int number){    
    int Remender = 0, total = 0;    
        
    //Compute the total of squares of digits    
    while(number > 0){    
        Remender = number%10;    
        total = total + (Remender*Remender);    
        number = number/10;    
    }    
    return total;    
}    
        
int main()    
{    
    int number ;
    printf("Enter the number \n");
    scanf("%d",&number);
        
    int outcome = number;    
        
    while(outcome != 1 && outcome != 4){    
        outcome = CheckHappyNo(outcome);    
    }    
        
    //The HapyNum alwys ends with 1    
    if(outcome == 1)    
        printf("This number is a Happy Number");    
    //The number which is not HappyNum ends in a cycle of numbers repeating contains 4    
    else if(outcome == 4)    
        printf("This number isn't a Happy Number");     
     
    return 0;    
}    

/*

OUTPUT: 
  
Enter the number 
85
This number isn't a Happy Number

*****************************************************************
Enter the number 
1
This number is a Happy Number

	Input : A number
	Output: Whether is Happy number or not
	Algorithm: C program to check whether a number is Happy Number or not

    
    Time Complexity: O(n)
    Space Complexity: O(n)

*/