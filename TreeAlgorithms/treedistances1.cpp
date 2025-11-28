#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second

int getinf(vi & parents, vector<pi> & longuestdown, vector<vi> & adj, vector<bool> & visited, int curr){
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            parents[u] = curr;
            longuestdown[curr].S = max(getinf(parents, longuestdown, adj, visited, u)+1, longuestdown[curr].S);
            if(longuestdown[curr].S > longuestdown[curr].F) swap(longuestdown[curr].S, longuestdown[curr].F);
        }
    }
    return longuestdown[curr].F;
}

void final(vector<bool> & visited, vector<vi> & adj, vector<pi> &maxdists, vi & parents, int curr){
    visited[curr] = true;
    if(maxdists[parents[curr]].F-1 == maxdists[curr].F){
        maxdists[curr].S = max(maxdists[curr].S, maxdists[parents[curr]].S + 1);
    }
    else{
        maxdists[curr].S = max(maxdists[curr].S, maxdists[parents[curr]].F + 1);
    }
    if(maxdists[curr].S > maxdists[curr].F) swap(maxdists[curr].S, maxdists[curr].F);
    for(auto u: adj[curr]){
        if(!visited[u]) final(visited, adj, maxdists, parents, u);
    }
}

int main(){
    int n,a,b;
    cin >> n;
    vector<vi> adj(n);
    vi parents(n);
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n,false);
    vector<pi> maxdists(n, {0,0});
    getinf(parents, maxdists, adj, visited, 0);
    visited = vector<bool>(n, false);
    visited[0] = true;
    for(auto u: adj[0]){
        final(visited, adj, maxdists, parents, u);
    }
    for(auto u: maxdists) cout << u.F << " ";
}