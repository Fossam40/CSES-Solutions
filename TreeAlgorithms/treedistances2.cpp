#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll subtree_nodes(vector<vl> & adj, vector<bool> & visited, int curr, vl & dists, ll & allc, ll depth){
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            dists[curr] += subtree_nodes(adj, visited, u, dists, allc, depth + 1);
        }
    }
    allc += depth;
    return dists[curr];
}

void finaldist(vector<vl> & adj, vector<bool> & visited, vl & sums,ll prev,int curr, vl & dists){
    visited[curr] = true;
    sums[curr] = prev - 2*dists[curr] + adj.size();
    for(auto u: adj[curr]){
        if(!visited[u]){
            finaldist(adj, visited, sums, sums[curr], u, dists);
        }
    }
}

int main(){
    ll n,a,b; cin >> n;
    vector<vl> adj(n);
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    vl dists(n,1);
    ll allc = 0;
    subtree_nodes(adj, visited, 0, dists, allc, 0);
    visited = vector<bool>(n,false);
    vl sums(n,0);
    sums[0] = allc;
    visited[0] = true;
    for(auto u: adj[0]){
        finaldist(adj, visited, sums, allc, u, dists);
    }
    for(auto a: sums) cout << a << " ";
}