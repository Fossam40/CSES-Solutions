#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vl> madj(n, vl(n,0));
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        madj[a-1][b-1]++;
    }
    vector<vl> dp(1<<(n-1), vl(n-1,0));
    for(int i = 0; i<(n-1); i++){
        dp[1<<i][i] = madj[0][i+1];
    }
    for(int i = 1; i<(1<<(n-1)); i++){
        for(int j = 0; j<(n-1); j++){
            if(i&(1<<j)){
                for(int k = 0; k<(n-1); k++){
                    if(madj[k+1][j+1]) dp[i][j] = (dp[i][j] + madj[k+1][j+1]*dp[i^(1<<j)][k]) % (ll)(1e9 + 7);
                }
            }
        }
    }
    if(n>=2)cout << dp[(1<<(n-1))-1][n-2] << "\n";
    else cout << 1 << "\n";
}