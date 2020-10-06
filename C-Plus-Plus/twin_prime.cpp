#include<iostream>
#include<vector>
using namespace std;

// helper function to check if a number if prime or not
bool isprime(int a){
  for(int i=2;i*i<=a;i++)
    if(a%i==0) return false;
  return true;
}

int main(){

  int a,b;
  cin>>a>>b;// input
  vector <int> prime;
  for(int i=a;i<b;i++){
    if(isprime(i))
      prime.push_back(i);
  }

  cout<<"Twin primes are: \n";
  for(int i=0;i<prime.size();i++){
    if(prime[i]+2==prime[i+1])
      cout<<prime[i]<<' '<<prime[i+1]<<endl;
  }

  return 0;
}
/*
twin prime are prime numbers which are two unit away from each other.

Implimentation:
  taking two input finding all prime in between them 
  then comparing adjacent numbers in vector if they differ by 2 or not  

Input:
  a and b specifing range

output:
  pair of twin prime

Sample Input-Output:
  Input1:
    1 10
  
  Output1:
    Twin primes are:
    3 5
    5 7

  Input2:
    1 100
  Output2:
  Twin primes are:
  3 5
  5 7
  11 13
  17 19
  29 31
  41 43
  59 61
  71 73

Time Complexity= O((a-b)*sqrt(b))
By prime number theory 
  number of prime number from 1 to n ~ n/log n
Space complexity = O(b/log(b)-a/log(a))
Contributed by : Hitansh K Doshi(github id: Hitansh159)
*/
