#include <iostream>
using namespace std;
int main(){
    int N,no,ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>no;
        ans = ans ^ no;
    }
    cout<<ans<<endl;
    /*
        Sample Input #1: 1 1 2 3 3 4 4 5 5
        Output : 2
        Sample Input #2: 1 2 2 3 3 4 5 4 5
        Output : 1
        Time Complexity : O(N)
        Space Complexity : O(1)
    */
}