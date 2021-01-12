#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;


void solve(){
    int n;
    cin >> n;
    vector<int> array;
    int ele;
    for(int i=0; i<n; i++){
        cin >> ele;
        array.push_back(ele);
    }
    sort(array.begin(), array.end());
    unordered_map<int,int> memo{};
    int count = 0;
    for(int i=0; i<n; i++){
        ele = array[i];
        if(!(memo[ele])){
            count++;
            memo[ele]=1;
        }
        else{
            if(!(memo[ele+1])){
                memo[ele+1] = 1;
                count++;
            }
        }
    }
    cout << count << endl;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}


