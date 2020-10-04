/**
* Implementation of Search Repeating elements
* https://github.com/sukritishah15/DS-Algo-Point/issues/83
* Contributed by @jhoserpacheco : https://github.com/jhoserpacheco
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int array[] = {0, 2, 2, 3, 4, 5, 7, 5, 8, 4, 8, 6, 4, 2, 1, 4, 7, 8};
	map<int, int> mymap;
	for(int i : array){
		if(mymap.count(i) == 0){
			mymap[i] = 1;
		}else{
			mymap[i]++;
		}
	}
	/**
	 * print all occurrences of all elements
	*/
	for(auto &x : mymap){
		cout << "Element [" << x.first << "] : " << x.second << " occurrences\n";
	}

	/**
	 * search the occurrences of a single element, where f is a element
	*/
	int f = 2;
	cout << "\nElement [" << f << "] : " << mymap[f] << " occurrences\n";
	return 0;
}


/*

Sample I/O-

Input
array = {0, 2, 2, 3, 4, 5, 7, 5, 8, 4, 8, 6, 4, 2, 1, 4, 7, 8}   |    2

Ouput
search occurrences of single element

Element [2] : 3 occurrences

Time Complexity - O(n)
Space Complexity - O(n)

*/
