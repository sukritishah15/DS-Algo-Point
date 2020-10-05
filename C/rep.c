//This time complexity and space complexity of this code is O(n)


/*Sample input: 5
		1 2 3 1 3
		
	 output: Repeated elements are
	 	 1
	 	 3	
*/

#include <stdio.h>
#include <stdlib.h>
 
int main() 
{ 
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int freq[100000]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    printf("Repeated elements are: \n");
    for(int i=0;i<100000;i++){
        if(freq[i]>1) printf("%d\n",a[i]);
    }
     
    return 0; 
} 
