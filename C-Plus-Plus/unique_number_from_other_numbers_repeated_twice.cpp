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
}