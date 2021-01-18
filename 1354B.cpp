#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limit = 1000001;

void solve(){
    string s;
    cin >> s;
    ll memo[3] = {0};
    ll ans = limit;
    for(int i=0; i<s.length(); i++){
        ll digit = s[i] - '0';
        memo[digit-1] = i+1;
        if(!(memo[0])||!(memo[1])||!(memo[2])){
            continue;
        }
        ans = min(ans, i+2-min(min(memo[0],memo[1]),memo[2]));
    }
    if(ans == limit){
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}


