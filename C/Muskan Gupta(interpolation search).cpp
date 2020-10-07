#include<stdio.h>
#include<conio.h>

int inter(int a[], int l, int h, int key){
    int p; 
    while((a[h]!=a[l])&&(key>=a[l])&&(key<=a[h])){
        p= l + ((key - a[l])/(a[h] - a[l]))*(h-l)  ;
        if(key < a[p])
            h = p-1;
        else             
            l= p+1;
        if(key == a[p])
            return p;  
    }
   return -1;
}


int main(){
    int n,key,i,f;
    printf("\nEnter no of elements for array");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements for array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    printf("\nEnter element which needs to be searched: ");
    scanf("%d", &key);
    f= inter(a, 0, n-1, key);
    if(f == -1)
        printf("\nElement %d not found", key);
    else
        printf("\nElement %d found at location %d\n", key, f+1);
    return 0; 
}


