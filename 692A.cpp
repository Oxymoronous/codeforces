#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll mod = 1000000007;

void solve(){
    string message;
    int len;
    cin >> len;
    cin >> message;
    int start = len-1;
    int count = 0;
    while(start>=0){
        if(message[start] == ')'){
            count++;
            start--;
        }
        else break;
    }
    if(len-count<count){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
}
int main(){
    ll cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}




