#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    ull x;
    cin >> n >> x;
    vector<ull> array;
    for(int i=0; i<n; i++){
        ull ele;
        cin >> ele;
        array.push_back(ele);
    }
    vector<int> memo;
    int exp;
    for(int j=0; j<n; j++){
        ull ele = array[j];
        exp = 0;
        while(ele%x==0){
            ele/=x;
            exp += 1;
        }
        memo.push_back(exp);
    }
    int index;
    int m = 50;
    for(int j=0;j<n; j++){
        if(memo[j]<m){
            m = memo[j];
            index = j;
        }
    }
    ull ans = 0;
    for(int i=0; i<n; i++){
        ans += (m+1)*array[i];
    }
    for(int i=0; i<index; i++){
        ans += array[i];
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
