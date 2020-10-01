//Implement Code to Check Whether a Number is Neon or Not (Issue #21)
//https://github.com/sukritishah15/DS-Algo-Point/issues/21
//Contributed by @tauseefmohammed2 : https://github.com/tauseefmohammed2

#include<iostream>
using namespace std;

//Function to Check Neon Numbers
bool NeonNumber(int num){
    int squareNum, lastDigit, sumOfDigits = 0;
	squareNum = num * num;

	while(squareNum > 0){
		//Obtaining the Last Digit by Applyting "%" - Modulo Operator with 10
		lastDigit = squareNum % 10;
		sumOfDigits += lastDigit;
		squareNum /= 10;
	}

	//Checking if the Sum of All Digits of the Number is Equal to the Number Itself(Neon or Not)
	if(sumOfDigits == num)
		return true;
	else
		return false;
}

int main(){
	int num;
	bool result;
	cout << "Enter a Number : ";
	cin >> num;
	result = NeonNumber(num);
	if(result)
		cout << endl << num << " is a Neon Number";
	else
		cout << endl << num << " in Not a Neon Number";
}

/*
Input : 9
Output : 9 is a Neon Number

Input : 15
Output : 15 is Not a Neon Number

Input : 1
Output : 1 is a Neon Number 

Time Complexity: O(digits)
Space Complexity: O(1)
*/
