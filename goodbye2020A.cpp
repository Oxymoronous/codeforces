#include<bits/stdc++.h>
using namespace std;
typedef long long ull;

double area(int x1, int y1, int x2, int y2, int x3, int y3){
    double ans = (x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2));
    ans/=2;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    ull count = 0;
    int coor[n];
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        coor[i] = c;
    }
    unordered_map<double,int> memo{};
    for(int j=0; j<n; j++){
        for(int i=j+1; i<n; i++){
            double a = area(0,1,coor[i],0,coor[j],0);
            if(memo[a]) continue;
            else{
                count += 1;
                memo[a] = 1;
            }
        }
    }
    cout << count << endl;
    return;
}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
        solve();
    }
}
