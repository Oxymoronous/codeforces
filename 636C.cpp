#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll ele;
    ll array[n];
    for(int i=0; i<n; i++){
        cin >> ele;
        array[i] = ele;
    }

    //maximum length: base case: no number: length = 0;
    //                          1 number: length = 1;
    //transition: dp[i] = dp[i-1] + 1 (if different signs)
    //            dp[i] = dp[i-1]
    ll dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        ele = array[i];
        ll prev = array[i-1];
        if(prev*ele<0)dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    }
    ll length = dp[n-1];
    ll start = 1;
    ll ans = 0;
    ll tmp = -1e15;
    for(int i=0; i<n; i++){
        if(dp[i] == start){
            tmp = max(tmp,array[i]);
        }else if(dp[i] > start){
            start = dp[i];
            ans += tmp;
            tmp = array[i];
        }
    }
    ans += tmp;
    cout << ans << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
