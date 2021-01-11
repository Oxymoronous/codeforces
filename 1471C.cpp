#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<ull> friends;
    ull f;
    for(int i=0;i<n; i++){
        cin >> f;
        friends.push_back(f);
    }
    vector<ull> prices;
    ull p;
    for(int i=0; i<m; i++){
        cin >> p;
        prices.push_back(p);
    }
    sort(friends.begin(), friends.end(), greater<>());
    int index = 0;
    ull ans = 0;
    for(int i=0; i<n; i++){
        ull limit = friends[i]-1;
        ull poss = prices[limit];
        if(limit < index){
            ans += poss; //directly giving money
        }else if(prices[index]>poss){
            ans += poss; //directly giving them the money (not buying the present)
        }else{
            ans += prices[index]; //getting the cheapest gift
            index += 1;
        }
    }
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

// 4 3 3 2 2
// 3 5 12 20
