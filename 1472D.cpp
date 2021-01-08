#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    ull array[n];
    vector<ull> odd;
    vector<ull> even;
    for(int i = 0; i<n; i++){
        ull ele;
        cin >> ele;
        array[i] = ele;
        if (ele%2==0){
            even.push_back(ele);
        }else{
            odd.push_back(ele);
        }
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int turn = 0;
    ull a = 0;
    ull b = 0;
    while(turn<n){
        if(turn%2==0){
            //Alice's turn
            if(even.empty()){
                odd.pop_back();
                turn+=1;
            }else if(odd.empty()){
                a += even.back();
                even.pop_back();
                turn += 1;
            }else if(odd.back() <= even.back()){
                a += even.back();
                even.pop_back();
                turn += 1;
            }else if(odd.back()>even.back()){
                odd.pop_back();
                turn += 1;
            }
        }
        else{
            if(odd.empty()){
                even.pop_back();
                turn+=1;
            }else if(even.empty()){
                b += odd.back();
                odd.pop_back();
                turn += 1;
            }else if(odd.back() >= even.back()){
                b += odd.back();
                odd.pop_back();
                turn += 1;
            }else if(odd.back()<even.back()){
                even.pop_back();
                turn += 1;
            }
        }
    }
    if(a == b){
        cout << "Tie" << endl;
        return;
    }else if(a>b){
        cout << "Alice" << endl;
        return;
    }else{
        cout << "Bob" << endl;
        return;
    }
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
