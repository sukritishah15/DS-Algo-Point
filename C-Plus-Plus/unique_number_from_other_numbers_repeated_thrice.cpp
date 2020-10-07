#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N,num;
	cin>>N;
	vector<int> sumOfBits(64,0);//Largest Integer can have atmost 64 bits so max array size - 64
	for(int i=0;i<N;i++){
		cin>>num;
		int j = 0;
		while(num > 0){
			int lastBit = num & 1;
			sumOfBits[j++] += lastBit;
			num = num >> 1;
		}
	}
	int p=1,ans = 0;
	for(int i=0;i<64;i++){
		sumOfBits[i] %= 3;
		ans = ans + (sumOfBits[i] * p);
		p = p * 2;
	}
	cout<<ans<<endl;
	return 0;
    /*
        Note : This logic can also be extended to numbers of form 5N+1,7N+1 ...
		Sample Input : 
		7
		1 1 1 2 3 3 3
		Output : 2
        Time Complexity : O(Nlog(num))
        Space Complexity : O(1)
    */
}