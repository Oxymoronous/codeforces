#include<bits/stdc++.h>
using namespace std;
typedef long long ull;

void solve(){
    ull n,k;
    cin >> n >> k;
    ull array[n];
    ull ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        array[i] = ele;
    }
    ull mi = array[0]; //start from the ground at first
    ull ma = array[0];
    for(int i=1; i<n; i++){
        mi = mi-(k-1);
        ma = ma+(k-1);
        mi = max(array[i], mi);
        ma = min(array[i]+(k-1),ma);
        if(mi>ma){
            cout << "no" << endl;
            return;
        }
    }
    if(mi == array[n-1]){
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        solve();
    }
}
