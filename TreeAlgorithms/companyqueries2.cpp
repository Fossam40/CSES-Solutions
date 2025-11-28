#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

void dfs(vector<bool> & visited, vl & depth,vector<vl> & dp, vector<vl> & adj, int curr){
    visited[curr] = true;
    int i = 1;
    while(i<dp[curr].size() && dp[curr][i-1]!=0){
        dp[curr][i] = dp[dp[curr][i-1]][i-1];
        i++;
    }
    for(auto u: adj[curr]){
        if(!visited[u]){
            dp[u][0] = curr;
            depth[u] = depth[curr] + 1;
            dfs(visited, depth, dp, adj, u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<vl> adj(n);
    vl depth(n, 0);
    int a;
    for(int i = 1; i<n; i++){
        cin >> a;
        adj[a-1].push_back(i);
        adj[i].push_back(a-1);
    }
    vector<bool> visited(n, false);
    int logn = 32 - __builtin_clz(n);
    vector<vl> dp(n, vl(logn, 0));
    dfs(visited, depth, dp, adj, 0);
    int b;
    for(int i = 0; i<q; i++){
        cin >> a >> b;a--;b--;
        if(depth[b]>depth[a]) swap(a,b);
        while(depth[a]>depth[b]){
            int logd = 31 - __builtin_clz(depth[a]-depth[b]);
            a = dp[a][logd];
        }
        for(int i = logn-1; i>=0; i--){
            while(dp[a][i]!=dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        if(a!=b) cout << dp[a][0] +1 << "\n";
        else cout << a+1 << "\n";
    }
}