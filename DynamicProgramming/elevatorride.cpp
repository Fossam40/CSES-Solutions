#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second

int main(){
    int n,x;
    cin >> n >> x;
    int w[n];
    for(int i = 0; i<n; i++){
        cin >> w[i];
    }
    pi arr[1 << n];
    arr[0] = {1,0};
    for(int i = 1; i< (1<<n); i++){
        arr[i] = {n, w[0]};
        for(int j = 0; j< n; j++){
            if(i & (1<<j)){
                auto pos = arr[i ^ (1<<j)];
                if(pos.S + w[j] > x){
                    pos.F++;
                    pos.S = w[j];
                }
                else{
                    pos.S += w[j];
                }
                arr[i] = min(pos, arr[i]);
            }
        }
    }
    cout << arr[(1<<n) - 1].F << "\n";
}