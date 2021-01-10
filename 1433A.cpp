//given an array of integers and a sum, print all subsets of given array with
//sum equal to given sum
//assumption: array consists of only positive integers

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string str = to_string(n);
    int ans = 0;
    int foo = str.length();
    while(foo){
        ans += foo;
        foo--;
    }
    ans += ((n%10)-1)*10;
    cout << ans << endl;
    return;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
