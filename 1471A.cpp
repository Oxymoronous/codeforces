#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    ull x;
    cin >> n >> x;
    ull array[n];
    for(int i=0; i<n; i++){
        ull ele;
        cin >> ele;
        array[i] = ele;
    }
    ull ma = 0;
    ull mi = 0;
    for(int i=0; i<n; i++){
        ull ele = array[i];
        if(ele%x == 0){
            ma += ele/x;
        }else{
            ma += ((ele/x)+1);
        }
    }
    ull sum = 0;
    sum = accumulate(array,array+n,sum);
    if(sum%x == 0){
        mi = sum/x;
    }else if(sum>x){
        mi = (sum/x)+1;
    }else if(sum<x){
        mi = 1;
    }
    cout << mi << " " << ma << endl;
    return;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
