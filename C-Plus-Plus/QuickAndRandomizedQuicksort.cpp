#include<bits/stdc++.h>
using namespace std;

int partition(int A[],int s,int e){
	int pivot=A[e];
	int pindx=s;
	for(int i=s;i<=e-1;i++){
		if(A[i]<=pivot){
			swap(A[i],A[pindx]);
			pindx++;
		}
	}
	swap(A[pindx],A[e]);
	return pindx;
}

int randompartition(int A[],int s,int e){
	int pindx = (rand() %(e - s + 1)) + s;
	swap(A[pindx],A[e]);
	return partition(A,s,e);
}

void quickSort(int *A,int s,int e){
	if(s>=e)
		return;
	int pindx=randompartition(A,s,e);
	quickSort(A,s,pindx-1);
	quickSort(A,pindx+1,e);
}

int main(){
	int A[]={5,2,7,11,-3,4,66,12};
	int n=sizeof(A)/sizeof(A[0]);
	//-3,2,4,5,7,11,12,66
	quickSort(A,0,n-1);

	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
}

/*NOTE: Randomized Partition is always recommended because if by chance extreme element (minimum or maximum)
is selected then time complexity will be worst aka O(n^2), Randomized partition increases the probability
such that non extreme element is selected as pivot this will result in time complexity of O(nlogn), which is
far better than O(n^2).*/
