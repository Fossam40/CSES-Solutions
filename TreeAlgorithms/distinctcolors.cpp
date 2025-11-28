#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


void solve(vector<vi> & adj, vector<bool> & visited, vi & distinct, vector<set<int>> & pos, int curr){
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            solve(adj, visited, distinct, pos, u);
            if(pos[u].size() > pos[curr].size()) swap(pos[curr], pos[u]);
            for(auto a: pos[u]){
                pos[curr].insert(a);
            }
        }
    }
    distinct[curr] = pos[curr].size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vi> adj(n);
    vi distinct(n);
    vector<set<int>> pos(n);
    int a,b;
    for(int i = 0; i<n; i++){
        cin >> a;
        pos[i].insert(a);
    }
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n,false);
    solve(adj, visited, distinct, pos, 0);
    for(auto a: distinct) cout << a << " ";
    cout << "\n";
}