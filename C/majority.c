#include <stdio.h>
#include <stdlib.h>


//This time complexity of this code is O(nlogn) and space complexity is O(1)
/* Sample input: 7
		  2 2 2 3 3 1 2
	  output: 2
*/	  	  
  
void mergealgo(int* arr,int l,int m,int r) 
{ 
    int i,j,k; 
    int n1=m-l+1; 
    int n2=r-m; 
    int a[n1],b[n2]; 

    for(i =0;i<n1;i++) 
        a[i]=arr[l+i]; 
    for(j=0;j<n2;j++) 
        b[j]=arr[m+1+j]; 
    i=0; 
    j=0;  
    k=l; 
    while(i<n1&&j<n2){ 
        if(a[i]<=b[j]){ 
            arr[k]=a[i]; 
            i++; 
        } 
        else{ 
            arr[k]=b[j]; 
            j++; 
        } 
        k++; 
    } 

    while(i<n1){ 
        arr[k]=a[i]; 
        i++; 
        k++; 
    } 

    while(j<n2){ 
        arr[k]=b[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int* arr,int l,int r) 
{ 
    if(l<r) { 
        int m=l+(r-l)/2;  
        merge_sort(arr, l, m); 
        merge_sort(arr, m + 1, r); 
  
        mergealgo(arr,l,m,r); 
    } 
} 
    

  
int main() 
{ 
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
  	scanf("%d",a+i);
  }
  merge_sort(a,0,n-1);   
  int count=1;
  int maxcount=-1000;
  int x=a[0];
  int ans;
  int flag=-1;
  for(int i=1;i<n;i++){
  	if(x==a[i]){
  	count++;
  	}
  	else{
  	  count=1;
  	  x=a[i];
  	}
  	if(maxcount<count){
  	maxcount=count;
  	ans=a[i];
  	if(maxcount>n/2){
  	    flag=1;
  	    break;
  	 }
  	 }
  	 
  	
  }
  if(flag==1){
    printf("%d\n",ans);
  }
  else{
    printf("No majority element\n");
  }
  
    return 0; 
} 
