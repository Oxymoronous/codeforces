#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    ull array[n];
    ull ele;
    for (int i = 0; i<n; i++){
        cin >> ele;
        array[i] = ele;
    }

    ull dp[n];
    for (int i=0; i<n; i++){
        dp[i] = 0;
    }

    for(int i=n-1; i>=0; i--){
        ull score = 0;
        int j = i;
        while(j<n){
            if(dp[j]){
                score += dp[j];
                break;
            }
            score += array[j];
            j += array[j];
        }
        dp[i] = score;
    }
    ull tmp = 0;
    for(int i=0; i<n; i++){
        if(dp[i]>tmp){
            tmp = dp[i];
        }
    }
    cout << tmp << endl;
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
}
