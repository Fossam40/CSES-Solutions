#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vi> logdists(31,vi(n));
    int a,b;
    for(int i = 0; i<n; i++){
        cin >> b;
        logdists[0][i] = b-1;
    }
    for(int i = 1; i< 31; i++){
        for(int j = 0; j<n; j++){
            logdists[i][j] = logdists[i-1][logdists[i-1][j]];
        }
    }
    for(int i = 0; i<q; i++){
        cin >> a >> b;
        int curr = a-1;
        while(b!=0){
            int logdown = 31 - __builtin_clz(b);
            curr = logdists[logdown][curr];
            b -= (1<<logdown);
        }
        cout << curr + 1 <<"\n";
    }
}