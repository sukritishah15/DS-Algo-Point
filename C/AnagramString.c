#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool checkAnagram(char* s1,char* s2){
   int hash1[256]={0};    //initialize arrays of size 256(maximum ASCII value for letters)
   int hash2[256]={0};    //to keep track of frequencies of occurrences of all the alphabets
   int i=0;               //to point to indexes
   if(strlen(s1)!=strlen(s2)){   //strings can't be anagrams if they don't have same length
      return false;
   }
   for(i=0;s1[i]&&s2[i];i++){
      hash1[s1[i]]++;          //update count of
      hash2[s2[i]]++;          //all the alphabets
   }
   for(int i=0;i<256;i++){
      if(hash1[i]!=hash2[i]){   //if frequency of two letters is different
         return false;          //that means strings are not anagrams.
      }
   }
   return true;
}

int main(){
  char s1[100];
  gets(s1);        //input first string
  char s2[100];
  gets(s2);        //input second string
  if(checkAnagram(s1,s2)){       //function call for checking anagrams
     printf("Given strings are anagrams of each other");
  }else{
     printf("Given strings are not anagrams of each other");
  }
}
/*
-:Sample Input:-
gRab
bRag
-:Sample Output:-
Given strings are anagrams of each other
-:Time Complexity:-
O(n) where n is the size of the input strings.
-:Space Complexity:-
O(1)
*/
