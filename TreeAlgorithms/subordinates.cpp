#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define int long long

int dfs(vector<vi> & adj, vi & ans, int curr){
    for(auto u: adj[curr]){
        ans[curr] += dfs(adj, ans, u) + 1;
    }
    return ans[curr];
}
signed main() {
    int n; cin >> n;
    vector<vi> adj(n);
    vi ans(n,0);
    int x;
    for(int i = 1; i<n; i++){
        cin >> x;
        adj[x-1].push_back(i);
    }
    int ign = dfs(adj, ans, 0);
    for(auto u: ans) cout << u << " ";
}