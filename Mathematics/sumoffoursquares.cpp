#include <bits/stdc++.h>
using namespace std;

const int C = (int)(1e7 + 1);

int main() {
    int t; cin >> t; int x;
    int** dp = (int**)malloc(sizeof(int*)*C);
    for(int i = 0; i<C; i++){
        dp[i] = (int*)malloc(sizeof(int)*4);
        dp[i][0] = -1;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for(int i = 0; i<60; i++){
        int q = i;
        for(int j = 0; j<4; j++){
            long long sq = 0;
            while((sq+1LL)*(sq+1LL) <= q) sq++;
            q-= sq*sq;
        }
        if(q>0) cout << "RIP " << i << "\n";
    }
    for(int i = 0; i<t; i++){
        cin >> x;
        cout << dp[x][0] << " " << dp[x][1] << " " << dp[x][2] << " " << dp[x][3] << "\n";
    } 
}