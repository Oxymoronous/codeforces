#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int is_palin(string a){
    if(a.length()==0) return 0;
    int left = 0;
    int right = a.length()-1;
    while(left<right){
        if(a[left]!=a[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
void solve(){
    string poem;
    cin >> poem;
    int length = poem.length();
    int count = 0;
    unordered_map<int,int> memo{};
    for(int i=1; i<length; i++){
        string two = "";
        string three = "";
        if(i >= 1){
            two = poem.substr(i-1,2);
        }
        if(i>=2){
            three = poem.substr(i-2,3);
        }
        if(is_palin(three)){
            if(!(memo[i]+memo[i-2])){
                count++;
                memo[i] = 1;
            }
        }
        if(is_palin(two)){
            if(!(memo[i]+memo[i-1])){
                count++;
                memo[i] = 1;
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
