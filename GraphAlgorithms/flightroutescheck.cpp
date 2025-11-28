#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void dfs(vector<vi> & adj, vector<bool> & visited, int curr){
    visited[curr] = true;
    for(auto u: adj[curr]) {
        if(!visited[u]) dfs(adj, visited, u);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> madj(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        madj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    vector<bool> mvisited(n, false);
    dfs(adj, visited, 0);
    dfs(madj, mvisited, 0);
    bool pos = true;
    int fromv;
    int tov;
    for(int i = 0; i<n; i++){
        if(!visited[i]) {
            pos = false;
            fromv = 0;
            tov = i;
        }
    }
    for(int i = 0; i<n; i++){
        if(!mvisited[i]) {
            pos = false;
            fromv = i;
            tov = 0;
        }
    }
    if(pos) cout << "YES\n";
    else {
        cout << "NO\n";
        cout << fromv +1<< " "<< tov+1 << "\n";
    }
}
