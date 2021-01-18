#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    string tmp;
    ll n =s.length();
    vector<ll> one = {};
    vector<ll> two = {};
    vector<ll> twone = {};

    //brief logic: identify substrings "one" "two" and "twone" (eliminates overlapping cases 
    //              (e.g. "twone") simultaneously)
    //              if "one" or "two", remove the second index, else, remove the third index

    //the problem solving part all happens in the loop below, rest are IO
    for(int i=0; i<n-2; i++){ // Q: the bug happens here, if i replace 'n' with s.length(), 
                             //     the code will get runtime error in some cases that I can't identify
        tmp = s.substr(i,3);
        if(tmp == "one"){
            if(i-2>=0){
                if(s.substr(i-2,5)=="twone") continue; //overlapping cases detection
            }
            one.push_back(i+2);
        }else if(tmp == "two"){
            string check = ".";
            if(i+4<n){
                check = s.substr(i, 5);
            }
            if(check == "twone"){
                twone.push_back(i+3);
            }else if(check != "twone"){
                two.push_back(i+2); //overlapping cases
            }
        }
    }

    //outputting stuff, no more logic
    ll count = one.size()+two.size()+twone.size();
    cout << count << endl;
    for(int i=0; i<one.size(); i++){
        cout << one[i] << " ";
    }
    for(int i=0; i<two.size();i++){
        cout << two[i] << " ";
    }
    for(int i=0; i<twone.size(); i++){
        cout << twone[i] << " ";
    }
    if(count == 0){
        return;
    }
    cout << "\n";
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
