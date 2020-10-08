//AnkitCode99 here....

// The problem statement goes like.

// You are given a dictionary of words and a sentence without any spaces.
// You have to check whether the sentence can be broken into sub-sentences 
// where each subsentence is a dictionary word.

#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

unordered_set<string> dictionary;


bool solve(ll idx,string str,vector<ll>& dp)
{
	if(idx==str.size())
	{
		return true;
	}

	if(dp[idx]!=-1)
	{
		return dp[idx];
	}

	for(ll i=idx+1;i<=str.size();i++)
	{
		string temp = str.substr(idx,i-idx);
		if(dictionary.find(temp)!=dictionary.end() and solve(i,str,dp))
		{
			return dp[idx]=true;
		}
	}

	return dp[idx]=false;
}

int main()
{

	ll dict_words;
	cin>>dict_words;
	for(ll i=0;i<dict_words;i++)
	{
		string temp;
		cin>>temp;
		dictionary.insert(temp);
	}

	string sentence;
	cin>>sentence;
	
	vector<ll> dp(sentence.size(),-1);

	cout<<solve(0,sentence,dp);


}//Goodbye...

/*

Sample input
12
i like sam sung samsung mobile ice cream icecream man go mango
ilikesamsung

Sample output
1

Reason - Sentence can be splitted as
i like samsung

Time Complexity - O(|S|^2)
Space Complexity - O(|S|)

*/
