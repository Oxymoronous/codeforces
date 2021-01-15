#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    ll ans = dp[n];
    cout << ans << endl;
}

int main(){
    int cases;
    while(cases--){
        solve();
    }
}