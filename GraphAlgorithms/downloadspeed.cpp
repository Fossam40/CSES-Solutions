#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second

int bfs(vector<vi> & adj, vector<vi> & cap, vi & parents){
    fill(parents.begin(), parents.end(), -1);
    parents[0] = -2;
    queue<pi> q;
    q.push({0,(int)(1e18)});
    while(!q.empty()){
        int curr = q.front().F;
        int flow = q.front().S; q.pop();
        for(auto u: adj[curr]){
            if(parents[u]==(-1) && (cap[curr][u]!=0)){
                parents[u] = curr;
                int nflow = min(flow, cap[curr][u]);
                if(u == (adj.size()-1)) return nflow;
                q.push({u,nflow});
            }
        }
    }
    return 0;
}

int edmond_karp(vector<vi> & adj, vector<vi> & cap){
    int n = adj.size();
    vi parents(n);
    int res = 0;
    int flow;
    while((flow=bfs(adj, cap, parents))){
        int curr = n-1;
        while(curr != 0){
            int next = parents[curr];
            cap[curr][next] += flow;
            cap[next][curr] -= flow;
            curr = next;
        }
        res += flow;
    }
    return res;
}

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> cap(n, vi(n,0));
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        cap[a-1][b-1] += c;
    }
    cout << edmond_karp(adj, cap) << "\n";
}