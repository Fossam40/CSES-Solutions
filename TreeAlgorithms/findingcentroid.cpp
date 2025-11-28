#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int ans = -1;

void solve(vector<vi> & adj, vector<bool> & visited, vi & size, int curr){
    visited[curr] = true;
    ans = curr;
    int nextcand = -1;
    for(auto u: adj[curr]){
        if(!visited[u]){
            if(size[u]>(adj.size()/2)) nextcand = u;
        }
    }
    if(nextcand != -1){
        int tmp = size[curr];
        size[curr] -= size[nextcand];
        size[nextcand] = size[curr];
        solve(adj, visited, size, nextcand);
    }
}

void getsizes(vector<vi> &adj, vector<bool>& visited, vi & size, int curr){
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            getsizes(adj, visited, size, u);
            size[curr] += size[u];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vi> adj(n);
    vi size(n,1);
    int a,b;
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n,false);
    getsizes(adj, visited, size, 0);
    visited = vector<bool>(n,false);
    solve(adj, visited, size, 0);
    cout << ans + 1 <<"\n";
}