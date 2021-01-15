#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e15;

//transition states of the dp:
//dp(i, mask) -> dp(i+1,mask)
//              dp(i+1,mask|M) + cost
//base case: dp(0,0) = 0
void solve(){
    ll n;
    cin >> n;

    /*brief explanation of logic:
    dp[n][mask] represents the minimum cost to obtain all the required vitamins for the juice.
    bitmasking is use to represent the three independent vitamins A,B,C respectively (A = 4, B = 2, C = 1)
    n represents the total number of juices being examined
    */
    ll dp[n+1][8];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<8; j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;

    for(int i=0; i<n; i++){
        ll price;
        string s;
        cin >> price >> s;
        int mask = 0; //mask represents the bitmask for the nutrition value of the current juice
        for(int j=0; j<3; j++){
            char foo = 'C' - j;
            bool have = 0;
            for(char d: s){
                if(d == foo){
                    have = 1;
                }
            }
            if(have){
                mask += (1<<j);
            }
        }
        for(int mask2=0; mask2<8; mask2++){
            dp[i+1][mask2] = min(dp[i+1][mask2],dp[i][mask2]); //Q1: why do we need to take the min of these two things?
                                                               //    I don't quite understand why it shouldnt be just 
                                                               // dp[i+1][mask2] = dp[i][mask]? (similar question for the line below, why is it not just the latter?)
            dp[i+1][mask2|mask] = min(dp[i+1][mask2|mask],dp[i][mask2]+price);
        }
    }
    ll ans = dp[n][7];
    if(ans == inf) ans = -1;
    cout << ans << endl;
}

int main(){
    solve();
}