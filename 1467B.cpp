#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull count(ull* array, int n){
    ull ans = 0;
    for(int i=1; i<n-1; i++){
        ull ele = array[i];
        if ((ele < array[i-1]) && (ele < array[i+1])){
            ans += 1;
        }else if((ele > array[i-1]) && (ele > array[i+1])){
            ans += 1;
        }
    }
    return ans;
}

ull hillorval(ull* array, int index, int n){
    if((index == 0) || (index == (n-1))){
        return 0;
    }else{
        ull left = array[index-1];
        ull right = array[index+1];
        if((array[index]<left)&&(array[index]<right)) return 1;
        if((array[index]>left)&&(array[index]>right)) return 1;
        return 0;
    }
}


void solve(){
    int n;
    cin >> n;
    ull array[n];
    for(int i = 0; i<n; i++){
        ull ele;
        cin >> ele;
        array[i] = ele;
    }
    if(n<=2){
        cout << 0 << endl; 
        return;
    }
    ull ori = count(array, n);
    ull c1, c2, m;
    vector<ull> foo;
    for(int j=1; j<n-1; j++){
        ull save = array[j];
        ull tmp = ori-(hillorval(array, j, n)+hillorval(array, j-1, n)+hillorval(array,j+1,n));
        array[j] = array[j-1];
        c1 = tmp+(hillorval(array, j, n)+hillorval(array, j-1, n)+hillorval(array,j+1,n));
        array[j] = array[j+1];
        c2 = tmp+(hillorval(array, j, n)+hillorval(array, j-1, n)+hillorval(array,j+1,n));
        array[j] = save;
        m = min(min(c1, c2), ori);
        foo.push_back(m);
    }
    m = *min_element(foo.begin(),foo.end());
    cout << m << endl;
    return;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}
