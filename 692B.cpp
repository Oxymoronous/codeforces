#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll mod = 1000000007;

int isfair(ull num){
    string s = to_string(num);
    int len = s.length();
    for(int i=0; i<len; i++){
        int digit = s[i]-'0';
        if(digit == 0) continue;
        if(num%digit!=0) return 0;
    }
    return 1;
}

void solve(){
    ull n;
    cin >> n;
    while(!(isfair(n))){
        n++;
    }
    cout << n << endl;
}
int main(){
    ll cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}




