#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int length = s.length();
    if (length%2==1){
        cout << "no" << endl;
        return;
    }
    char c;
    c = s[0];
    if (c == ')'){
        cout << "no" << endl;
        return;
    }
    int check = 0;
    for(int i = 0; i<length; i++){
        c = s[i];
        if (c == '?') continue;
        if (c == '(') check += 1;
        if (c == ')') check -= 1;
        if (check<0) break;
    }

    char c2;
    c = s[0];
    c2 = s[length-1];
    if (check<0){
        if ((c == c2) && (c2 == '?')){
            cout << "yes" << endl;
            return;
        }else{
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
    return 0;
}