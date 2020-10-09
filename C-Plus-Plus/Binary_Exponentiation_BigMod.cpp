//Problem find BigMod Using Binary Exponentian

#include<bits/stdc++.h>
using namespace std;
long long int bigmod(long long int a,long long int b,long long c)
{
	if(b==0){
		return 1;	
	}
	if(b%2==0){
		long long value=bigmod(a,b/2,c);
		return (value*value)%c;
	}
	else if(b%2==1){
		long long int x,y;
		x=a%c;
		y=bigmod(a,b-1,c);
		return (x*y)%c;
	}
	
}


int main()
{
	long long int a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<bigmod(a,b,c)<<endl;
	}
	return 0;
}

/*
Input : 3 18132 17 
example (3 POWER 18132 mod 17)=13
Output : 13
Time Complexity :  O(logn)
*/

