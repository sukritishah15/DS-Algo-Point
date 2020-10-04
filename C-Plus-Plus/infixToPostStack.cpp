// program for infix to postfix expression
#include<bits/stdc++.h>
using namespace std;
// function to check the precedence of character
int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// function to convert infix to postfix
void infixToPostfix(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++){
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
        st.push('('); 
        // if the scanned character is ')'
        else if(s[i] == ')'){
            // check for the '(' and end of stack
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top();
                st.pop();
                ns+=c;
            }
            if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
        }
        // if the scanned char is operator
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
                char c= st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
    while(st.top() != 'N'){
        char c = st.top();
        st.pop();
        ns+=c;
    }
    cout << ns << "\n";
}

// main function
int main(){
    string x = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(x);
    return 0;
}

/*
INPUT 
a+b*(c^d-e)^(f+g*h)-i

OUTPUT
a+b*(c^d-e)^(f+g*h)-i

Time Complexity O(n)
Space Complexity O(n)
*/