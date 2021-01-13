#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll mod = 1000000007;

void solve(){
    ll n;
    cin >> n;
    ll array[n];;
    ll ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        array[i] = ele;
    }
    ll power[62];
    for(int i =0; i<62; i++){
        power[i] = 0;
    }
    for(int i=0; i<n; i++){
        for(ll j=0; j<62; j++){
            if(array[i] & (1ll<<j)) ++power[j];
        }
    }
    ll answer = 0;
    for(int i=0; i<n; i++){
        ll andv = 0;
        for(ll j=0; j<62; j++){
            if (array[i] & (1ll<<j)){
                ll conv = (1ll<< j)%mod;
                andv = (andv+conv*power[j])%mod;
            }
        }
        ll orv = 0;
        for(ll j=0; j<62; j++){
            ll p = (1ll << j)%mod;
            if(array[i]&(1ll<<j)){
                orv = (orv+n*p)%mod;
            }else{
                orv = (orv +power[j]*p)%mod;
            }
        }
        answer = (answer + andv*orv)%mod;
        //Q: why cant I rewrite the line above as:
        //answer += (andv*orv)%mod?
    }
    cout << answer << endl;
}
int main(){
    ll cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}




