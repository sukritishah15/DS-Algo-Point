// Delete Middle Element From Stack
// Deleting index = (n/2 + 1) = k

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// small input 
// we can also thing with stack size

void DeleteMiddleElement(stack<int> &s, int k){
	if(k==1){
		s.pop();
		return;
	}

	int val = s.top();
	s.pop();

	DeleteMiddleElement(s, k-1);

	s.push(val);
}

int main(){
	stack<int> s;
	s.push(3);
	s.push(33);
	s.push(13);
	s.push(30);
	s.push(8);

	int k = s.size()/2 + 1;   // Middle Element of Stack

	DeleteMiddleElement(s, k);

	int sz = s.size();
	for(int i=0; i<sz; i++){
		cout<<s.top()<<" ";
		s.pop();
	}
}
