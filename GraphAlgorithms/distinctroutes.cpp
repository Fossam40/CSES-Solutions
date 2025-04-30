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

int vbfs(vvi & adj, vvi& cap, vi & parents){
    fill(parents.begin(), parents.end(), -1);
    parents[0] = -2;
    int n = adj.size();
    queue<int> q;
    q.push(0);
    bool found = false;
    while(!q.empty() && !found){
        int curr = q.front();q.pop();
        for(auto u: adj[curr]){
            if(parents[u]==-1 && (cap[curr][u]==0)){
                parents[u] = curr;
                if(u==(n-1)) found = true;
                q.push(u);
            }
        }
    }
    return(parents[n-1]!=-1);
}

int main(){
    int n,m;
    cin >> n >> m;
    vvi adj(n);
    vvi cadj(n);
    vvi cap(n, vi(n,0));
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        cadj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        cap[a-1][b-1]++;
    }
    cout << maxflow(adj, cap) << "\n";
    vi parents(n);
    while(vbfs(cadj,cap, parents)){
        stack<int> path;
        int curr = n-1;
        while(curr!=0){
            int prev = parents[curr];
            cap[prev][curr]=1;
            curr = prev;
            path.push(curr);
        }
        cout << path.size()+1 << "\n";
        while(!path.empty()){
            cout << path.top() +1<< " ";
            path.pop();
        }
        cout << n << "\n";
    }
}