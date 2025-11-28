#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
int parts;
set<pi> pairs;
vector<vi> finaladj;
vector<vi> revfinal;

void solve(int a, vector<vi> & adj){
    int last = adj[a][adj[a].size() -1];
    while(adj[a].size()!=0 && pairs.count({min(last,a), max(last,a)})==0){
        adj[a].pop_back();
        if(adj[a].size()!=0) last = adj[a][adj[a].size() -1];
    }
    while(adj[a].size()!=0){
        int nextel = adj[a][adj[a].size()-1];
        adj[a].pop_back();
        pairs.erase({min(a,nextel),max(a,nextel)});
        finaladj[a].push_back(nextel);
        revfinal[nextel].push_back(a);
        solve(nextel, adj);
        last = adj[a][adj[a].size() -1];
        while(adj[a].size()!=0 && pairs.count({min(last,a), max(last,a)})==0){
            adj[a].pop_back();
            if(adj[a].size()!=0) last = adj[a][adj[a].size() -1];
        }
    }
}


void dfs(vector<bool> & visited, vector<vi> & adj, int a){
    visited[a] = true;
    for(auto e : adj[a]){
        if(!visited[e]){
            dfs(visited, adj, e);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    finaladj = vector<vi>(n);
    revfinal = vector<vi>(n);
    parts = n;
    int a,b;
    vi uf(n);
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        pairs.insert({min(a-1,b-1), max(a-1,b-1)});
    }
    solve(0,adj);
    vector<bool> visited1(n,false);
    vector<bool> visited2(n, false);
    dfs(visited1, finaladj, 0);
    dfs(visited2, revfinal, 0);
    bool pos = true;
    for(int i = 0; i<n; i++){
        pos = pos && (visited1[i] && visited2[i]);
    }
    if(pos){  
        for(int i = 0; i<n ; i++){
            for(auto e: finaladj[i]){
                cout << i+1 << " " << e+1 << "\n";
            }
        }
    }
    else{
        cout << "IMPOSSIBLE\n";
    } 
}