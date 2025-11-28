#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

int bfs(vvi & adj, vvi& cap, vi & parents){
    fill(parents.begin(), parents.end(), -1);
    parents[0] = -2;
    int n = adj.size();
    queue<pi> q;
    q.push({0,(int)(1e9)});
    while(!q.empty()){
        int curr = q.front().F;
        int flow = q.front().S; q.pop();
        for(auto u: adj[curr]){
            if(parents[u]==-1 && cap[curr][u]){
                parents[u] = curr;
                int nflow = min(cap[curr][u],flow);
                if(u==(n-1)) return nflow;
                q.push({u,nflow});
            }
        }
    }
    return 0;
}

int maxflow(vvi& adj, vvi& cap){
    int n = adj.size();
    vi parents(n);
    int flow;
    int res = 0;
    while((flow = bfs(adj,cap, parents))){
        res += flow;
        int curr = n-1;
        while(curr!=0){
            int prev = parents[curr];
            cap[curr][prev]+=flow;
            cap[prev][curr]-=flow;
            curr = prev;
        }
    }
    return res;
}

int main(){
    int b,g,m;
    cin >> b >> g >> m;
    vvi adj(b+g+2);
    vvi cap(b+g+2,vi(b+g+2,0));
    int a,q;
    for(int i = 1; i<=b; i++){
        adj[0].push_back(i);
        cap[0][i]++;
    }
    for(int i = b+1; i<b+g+1; i++){
        adj[i].push_back(b+g+1);
        cap[i][b+g+1]++;
    }
    for(int i = 0; i<m; i++){
        cin >> a >> q;
        if(cap[a][b+q]==0){
            adj[a].push_back(b+q);
            adj[b+q].push_back(a);
            cap[a][b+q]++;
        }
    }
    cout << maxflow(adj,cap) << "\n";
    for(int i = 1; i<=b; i++){
        for(auto u: adj[i]){
            if(cap[i][u]==0){
                cout << i << " " << u-b << "\n";
            }
        }
    }
}