#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void topsort(vector<vi>& adj, vector<bool> & visited, stack<int> & order, int curr){
    if(!visited[curr]){
        visited[curr] = true;
        for(auto u: adj[curr]){
            topsort(adj, visited, order, u);
        }
        order.push(curr);
    }
}

void dfs(vector<vi>& adj, vector<bool> & visited, vi & components, int curr, int ccomp){
    if(!visited[curr]){
        visited[curr] = true;
        components[curr] = ccomp;
        for(auto u: adj[curr]){
            dfs(adj, visited, components, u, ccomp);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> madj(n);
    vector<int> prix(n);
    int a,b;
    for(int i = 0; i<n; i++){
        cin >> prix[i];
    }
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        madj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    stack<int> order;
    for(int i = 0; i<n; i++) topsort(madj, visited, order, i);
    visited = vector<bool>(n,false);
    vi components(n,0);
    int ccomp = 0;
    for(int i = 0; i<n; i++){
        int curr = order.top(); order.pop();
        ccomp += !visited[curr];
        dfs(adj, visited, components, curr, ccomp);
    }
    vector<vi> adg(ccomp);
    vl pcomp(ccomp,0);
    for(int i = 0; i<n; i++){
        pcomp[components[i]-1]+=prix[i];
        for(auto u: adj[i]){
            if(components[i] != components[u]) adg[components[i]-1].push_back(components[u]-1);
        }
    }
    vl dp(n,0);
    ll max_found = 0;
    for(int i = 0; i<ccomp; i++){
        dp[i] = pcomp[i];
        ll maxcont = 0;
        for(auto u: adg[i]){
            maxcont = max(maxcont, dp[u]);
        }
        dp[i] += maxcont;
        max_found = max(max_found, dp[i]);
    }
    cout << max_found << "\n";
}