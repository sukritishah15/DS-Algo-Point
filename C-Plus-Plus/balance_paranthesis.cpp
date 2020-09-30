#include<bits/stdc++.h>
using namespace std;

bool balance(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(st.top()=='{' && s[i]=='}'){
            st.pop();
        }
        else if(st.top()=='(' && s[i]==')'){
            st.pop();
        }
        else if(st.top()=='[' && s[i]==']'){
            st.pop();
        }
        else{
            break;
        }
    }
    if(!st.empty()){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    string s;cin>>s;
    if(balance(s)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}

/*
Given a string expression, check whether the pair and order of { }, ( ),[ ] are correct in expression.

For example-
Input: ({[]})
Output: Balanced

Input: (({})
Output: Not Balanced

Time complexity O(n)
Space complexity O(n)
*/
