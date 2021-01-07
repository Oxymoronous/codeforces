#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int w, h;
    ull n;
    cin >> w >> h >> n;
    ull sheets = 1;
    if(n == 1){
        cout << "yes" << endl;
        return;
    }
    while(!(w%2)){
        sheets*=2;
        w/=2;
    }
    while(!(h%2)){
        sheets*=2;
        h/=2;
    }
    if(sheets>=n){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
    return;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}