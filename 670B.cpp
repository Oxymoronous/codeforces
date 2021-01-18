#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll array[n];
    ll ele;
    for(int i=0;i<n; i++){
        cin >> ele;
        array[i] = ele;
    }
    vector<ll> pos;
    vector<ll> neg;
    for(int i=0; i<n; i++){
        ele = array[i];
        if(ele>=0) pos.push_back(ele);
        else neg.push_back(-ele);
    }
    ll ans = -1e18;
    sort(pos.rbegin(),pos.rend());
    sort(neg.rbegin(),neg.rend());
    for(int i=1; i<=5; i+=2){
        ll tmp = 1;
        if((pos.size()<i)||(neg.size()<5-i)) continue;
        for(int j=0; j<i; j++){
            tmp *= pos[j];
        }
        for(int j=0; j<5-i; j++){
            tmp *= neg[j];
        }
        ans = max(tmp,ans);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    for(int i=0; i<=5; i+=2){
        ll tmp = -1;
        if((pos.size()<i)||(neg.size()<5-i)) continue;
        for(int j=0; j<i; j++){
            tmp *= pos[j];
        }
        for(int j=0; j<5-i; j++){
            tmp *= neg[j];
        }
        ans = max(tmp,ans);
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