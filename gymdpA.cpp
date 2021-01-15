#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//f(n) = 2*f(n-2)
//base case: f(0) = 1; f(1) = 0
void solve(){
    ll n;
    cin >> n;
    ll dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    for(int i=2; i<n+1; i++){
        dp[i] = 2*dp[i-2];
    }
    cout << dp[n] << endl;
    return;
}

int main(){
    solve();
}