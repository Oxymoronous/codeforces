#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        int book;
        cin >> book;
        array[i] = book;
    }
    int moves = 0;
    int open = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        int book = array[i];
        if(book){
            if(!open){
                open = 1;
                count = i;
            }else{
                moves += (i-count-1);
                count = i;
            }
        }
    }
    cout << moves <<endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
