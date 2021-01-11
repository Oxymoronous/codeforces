#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<ull> array;
    for(int i=0; i<n; i++){
        ull ele;
        cin >> ele;
        array.push_back(ele);
    }
    int count = 0;
    ull ma = *max_element(array.begin(),array.end());
    int index = 0;;
    for(int i=0; i<n; i++){
        if(array[i] == ma){
            count ++;
        }
    }
    if(count == n){
        cout << -1 << endl;
        return;
    }
    for(int i=0; i<n; i++){
        if(array[i] == ma){
            if(((i-1)>=0)){
                if(array[i-1] < ma){
                    index = i;
                    break;
                }
            }if(((i+1)<n)){
                if(array[i+1] < ma){
                    index = i;
                    break;
                }
            }
        }
    }
    index += 1;
    cout << index<< endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
