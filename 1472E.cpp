#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<ull> height;
    vector<ull> width;
    ull w, h;
    for(int i=0; i<n; i++){
        cin >> h >> w;
        height.push_back(h);
        width.push_back(w);
    }
    vector<int> arrange;
    ull curh, curw;
    ull h2, w2;

    unordered_map<ull,ull> memo {};

    for(int i=0; i<n; i++){
        curh = height[i];
        curw = width[i];
        int done = 0;
        for(int j=0; j<n; j++){
            if(j == i) continue;
            h2 = height[j];
            w2 = width[j];
            if((h2<curh)&&(w2<curw)){
                arrange.push_back(j+1);
                done = 1;
                break;
            }else if((h2<curw)&&(w2<curh)){
                arrange.push_back(j+1);
                done = 1;
                break;
            }
        }
        if(!(done))arrange.push_back(-1);
    }
    for(int i=0; i<n; i++){
        cout << arrange[i] << " ";
    }
    cout << endl;
    return;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
