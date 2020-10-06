#include <stdio.h> 
  

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void DutchFlag(int a[], int n) 
{ 
    // sample input : 0 1 0 2 0
    // sample outpu : 0 0 0 1 2
    // Time complexity O(nlog(n)) 
    // Space complexity O(n)
    int l = 0; 
    int h = n - 1; 
    int m = 0; 
  
    while (m <= h) { 
        switch (a[m]) { 
        case 0: 
            swap(&a[l++], &a[m++]); 
            break; 
        case 1: 
            m++; 
            break; 
        case 2: 
            swap(&a[m], &a[h--]); 
            break; 
        } 
    } 
} 

int main() 
{   int n;
    scanf("%d",&n);
    int a[n] ; 
    for(int i = 0 ; i<n ;i++)
        scanf("%d",&a[i]);

    DutchFlag(a,n); 

    for(int i = 0 ; i<n ;i++)
        printf("%d ",a[i]);
    printf("\n"); 
    return 0; 
} 
// sample input : 0 1 0 2 0
// sample outpu : 0 0 0 1 2
// Time complexity O(nlog(n)) 
// Space complexity O(n)