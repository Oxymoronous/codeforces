#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MIN -100000

void solve(){
    int n1, n2;
    cin >> n1;
    int array[n1];
    for(int i=0; i<n1; i++){
        int red;
        cin >> red;
        array[i]=red;
    }
    cin >> n2;
    int array2[n2];
    for(int i=0; i<n2; i++){
        int blue;
        cin >> blue;
        array2[i] = blue;
    }
    int running = 0;
    int dp[n1+1][n2+1];
    for(int i=0; i<n1+1; i++){
        for(int j=0; j<n2+1; j++){
            dp[i][j] = MIN;
        }
    }
    dp[0][0] = 0;   //Q1: is this additional element for the case where nothing is taken from either list?
    int base = 0;
    for(int i=0; i<n1+1; i++){
        for(int j=0; j<n2+1; j++){
            if (i<n1){ //Q2: why are the two 'if's on line 33 line 36 needed? (what do they mean?)
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]+array[i]);
            }
            if (j<n2){
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]+array2[j]);
            }
            base = max(base, dp[i][j]);
        }
    }
    cout << base << endl;
    return;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}


