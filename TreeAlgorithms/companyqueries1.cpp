#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

void dfs(vector<vl> & adj, vector<int> & depths, vector<vl> & dp, vector<bool> & visited, int curr){
    visited[curr] = true;
    int i = 1;
    while(i<dp[curr].size() && dp[curr][i-1] != -1){
        dp[curr][i] = dp[dp[curr][i-1]][i-1]; i++;
    }
    for(auto u: adj[curr]){
        if(!visited[u]){
            dp[u][0] = curr;
            depths[u] = depths[curr] + 1;
            dfs(adj, depths, dp, visited, u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n>>q;
    int a,b;
    vector<vl> adj(n+1);
    for(int i = 1; i<n; i++){
        cin >> a;
        adj[a-1].push_back(i);
        adj[i].push_back(a-1);
    }
    int logn = 32 - __builtin_clz(n);
    vector<int> depths(n,0);
    vector<vl> dp(n, vl(logn, -1));
    vector<bool> visited(n, false);
    dfs(adj, depths, dp, visited, 0);
    for(int i = 0; i<q; i++){
        cin >> a >> b;a--;
        if(depths[a]<b) {cout << "-1\n";}
        else{
            while(b != 0){
                int logb = 31 - __builtin_clz(b);
                a = dp[a][logb];
                b -= (1<<logb);
            }
            cout << a +1<< "\n";
        }
    }
}