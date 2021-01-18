#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    ll dp[4] = {1,0,0,0};
    char last = 'a';
    for(char c:s){
        if(c=='o'){
            dp[2] += dp[1];
        }else if(last == 'v'){
            dp[1] += dp[0];
            dp[3] += dp[2];
        }
        last = c;
    }
    cout << dp[3] << endl;
}

int main(){
    solve();
}
