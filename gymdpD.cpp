#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin >> n >> k;
    ll lecture[n];
    ll ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        lecture[i] = ele;
    }
    int array[n];
    int foo;
    for(int i=0; i<n; i++){
        cin >> foo;
        array[i] = foo;
    }
    ll prefixsum[n]; //this stores the unaffected prefix sum (where we dont use the special ability)
    prefixsum[0] = array[0]*lecture[0];
    //prefix sum: ps(i) = a(i) + ps(i-1)
    ll suffixsum[n];
    //suffix sum: ss(i) = a(i) + ss(i+1)
    suffixsum[n-1] = array[n-1]*lecture[n-1];
    for(int i=1; i<n; i++){
        prefixsum[i] = array[i]*lecture[i] + prefixsum[i-1];
    }
    for(int i=n-2; i>=0; i--){
        suffixsum[i] = array[i]*lecture[i] + suffixsum[i+1];
    }
    ll range[n];
    ll s = 0;
    for(int i=0; i<n; i++){
        s += lecture[i];
        range[i] = s;
    }
    ll ans = 0;
    //dp transition:
    //dp[i] = unafp[i-1] + range + unafs[i+k];
    //range = ps[i+k-1] - ps[i-1]
    for(int i=0; i+k-1<n; i++){
        ll tmp = 0;
        if(i+k<n){
            tmp += suffixsum[i+k];
        }
        if(i>0){
            tmp += prefixsum[i-1];
        }
        tmp += range[i+k-1];
        if(i>0){
            tmp -= range[i-1];
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}

int main(){
    solve();
}
