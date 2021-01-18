#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll limit = 1000001;

void solve(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++){
        int ele;
        cin >> ele;
        array[i] = ele;
    }
    ll left[n];
    int s = 0;
    for(int i=0; i<n; i++){
        s+=array[i];
        left[i] = s;
    }
    ll right[n];
    s = 0;
    for(int i=n-1; i>=0; i--){
        s+= array[i];
        right[i] = s;
    }
    ll span[n][n];
    int zero;
    ll ans = -1;
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            if(i-1>=0){
                span[i][j] = j+1-left[j]-i+left[i+1];
                if(j+1>=n){
                    ans = max(ans,left[i-1]+span[i][j]);
                }else{
                    ans = max(ans,left[i-1]+span[i][j]+right[j+1]);
                }
            }else if(i-1<0){
                span[i][j] = j+1-left[j];
                if(j+1>=n){
                    ans = max(ans,span[i][j]);
                }else{
                    ans = max(ans,span[i][j]+right[j+1]);
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
}

