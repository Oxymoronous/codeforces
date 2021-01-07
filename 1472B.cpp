#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int i,j, candy;
    int array[n];
    for(i = 0; i<n; i++){
        cin >> candy;
        array[i] = candy;
    }
    for(i=0; i<n; i++){
        int foo = array[i];
        for(j=i+1; j<n; j++){
            int tmp = array[j];
            if(foo < tmp){
                array[j] = foo;
                array[i] = tmp;
            }
        }
    }
    for(i=0; i<n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
    int count = array[0];
    for(i=1; i<n; i++){
        candy = array[i];
        if (count == 0){
            count = candy;
            continue;
        }
        count -= candy;
        if (count<0){
            cout << "no" << endl;
            return;
        }
    }
    if(count){
        cout << "no" << endl;
        return;
    }
    cout << "yes" << endl;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}