#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
int bfs(vector<vi> & adj, vector<vi> & cap, vi& parents){
    int n = adj.size();
    fill(parents.begin(), parents.end(), -1);
    parents[0] = -2;
    queue<pi> q;
    q.push({0,(int)(1e9)});
    while(!q.empty()){
        int cur = q.front().F;
        int flow = q.front().S;q.pop();
        for(auto u: adj[cur]){
            if(parents[u] == -1 && cap[cur][u]){
                parents[u] = cur;
                int nflow = min(flow, cap[cur][u]);
                if(u==(n-1)) return nflow;
                q.push({u,nflow});
            }
        }
    }
    return 0;
}

int maxflow(vector<vi> & adj, vector<vi> & cap){
    int n = adj.size();
    int flow;
    int res = 0;
    vi parents(n);
    while(flow = bfs(adj, cap, parents)){
        res += flow;
        int curr = n-1;
        while(curr != 0){
            int prev = parents[curr];
            cap[prev][curr] -= flow;
            cap[curr][prev] += flow;
            curr = prev;
        }
    }
    return res;
}

void dfs(vector<vi> & adj, vector<vi> & cap, vector<bool> & visited, int curr){
    if(!visited[curr]){
        visited[curr] = true;
        for(auto u: adj[curr]){
            if(cap[curr][u]) dfs(adj, cap, visited, u);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> fadj(n);
    vector<vi> adj(n);
    vector<vi> cap(n,vi(n,0));
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        fadj[a-1].push_back(b-1); 
        fadj[b-1].push_back(a-1); 
        cap[a-1][b-1]++;
        cap[b-1][a-1]++;
    }
    cout << maxflow(fadj, cap) << "\n";
    vector<bool> visited(n,false);
    dfs(fadj, cap, visited, 0);
    for(int i = 0; i<n; i++){
        if(visited[i]){
            for(auto u: fadj[i]){
                if(!visited[u]){
                    cout << i +1<< " " << u+1 << "\n";
                }
            }
        }
    }
}
