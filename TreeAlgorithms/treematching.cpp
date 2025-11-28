#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
typedef vector<pi> vi;
#define S second
#define F first

void dfs(vector<vector<int>> & adj, vi & dp, vector<bool> & visited, int curr, int par){
    if(!visited[curr]){
        visited[curr] = true;
        for(auto u: adj[curr]){
            if(u!= par){
                dfs(adj, dp, visited, u, curr);
                dp[curr].S += dp[u].F;
                dp[curr].F = max(dp[curr].F, -dp[u].F + dp[u].S);
            }
        }
        dp[curr].F += dp[curr].S + 1;
    }
}
signed main() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vi dp(n,{(-1e18),0});
    int x, y;
    for(int i = 1; i<n; i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<bool> visited(n,false);
    for(int i = 1; i<n; i++){
        if(adj[i].size()==1){
            dp[i] = {0,0};
            visited[i] = true;
        }
    }
    dfs(adj, dp, visited, 0, -1);
    cout << max(dp[0].F,dp[0].S) << "\n";
}