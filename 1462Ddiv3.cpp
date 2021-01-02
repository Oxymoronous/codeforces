#include<bits/stdc++.h>
using namespace std;

void solve(){
    int length;
    cin >> length;
    vector<int> array;
    int num, sum = 0;
    for (int i = 0; i<length; i++){
        cin >> num;
        array.push_back(num);
        sum += num;
    }

    //j represents the number of (possible) subarrays
    //starts from the greatest number of subarrays because that implies the least number
    //of operations done
    for (int j = length; j>=1; j--){ 
        int testSum = 0;
        int currSum = 0;
        bool check = true;
        if (sum%j == 0){
            testSum = sum/j;
            for (int k=0; k<length; k++){
                currSum += array[k];
                if (currSum == testSum){
                    currSum = 0;
                }else if(currSum > testSum){
                    check = false;
                    break;
                }
            }
            if(check){
                cout << length - j << endl;
                return;
            }
        }
    }
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
    return 0;
}