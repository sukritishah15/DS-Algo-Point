#include<stdio.h>
#include<string.h>

int main(){
    char str[50];
    printf("Enter any string: ");
    scanf("%s",str);

    int l = 0, h= strlen(str)-1;
    while(l<h){
        if(str[l++] != str[h--]){
            printf("The given string is not a palindrome");
            return 0;
        }
    }
    printf("The given string is a palindrome");
    return 0;
}

/* Problem name: To check whether a string is palindrome or not 

   1)
   Input: 
   Enter any string: palaalap

   Output:
   The given string is a palindrome

   2)
   Input:
   Enter any string: hey

   Output:
   The given string is not a palindrome 

   
   Time Complexity: O(n)
   Space Complexity: O(n)


*/
