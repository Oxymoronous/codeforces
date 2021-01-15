#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//f(i) = f(i-1) + 1
//base case: f(0) = 0
void solve(){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    char array[k];
    for(int i=0; i<k; i++){
        char alpha;
        cin >> alpha;
        array[i] = alpha;
    }
    bool typeable[26] = {0};
    for(int i=0; i<k; i++){
        typeable[array[i] - 'a'] = 1; 
    }
    bool a[n] = {0};
    for(int i=0; i<n; i++){
        if(typeable[s[i] - 'a']){
            a[i] = 1;
        }
    }
    ll dp[n+1];
    dp[0] = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(!(a[i])){
            dp[i+1] = 0;
        }else{
            dp[i+1] = 1+dp[i];
        }
        ans += dp[i+1];
    }
    cout << ans << endl;
}

int main(){
    solve();
}