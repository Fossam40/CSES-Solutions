#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define F first
#define S second
void dfs(vector<pair<int,int>> & cycles, vi & cyclens, vi & status, vi & adj, vi & parents, int curr, int ccycle, int lcycle){
    if(status[curr]==0){
        status[curr]++;
        dfs(cycles, cyclens,status, adj, parents, adj[curr], ccycle, lcycle);
        status[curr] = 2;
    }
    if(status[curr]==1){
        if(ccycle == -1) {ccycle = curr;}
        cycles[curr] = {ccycle, lcycle};
        status[curr] = 2;
        if(status[adj[curr]]==2) cyclens[ccycle] = lcycle + 1;
        dfs(cycles, cyclens, status, adj, parents, adj[curr], ccycle, lcycle + 1);
    }
}
 
void depth_label(vector<vi> & adj, vector<pair<int,int>> & cycles, vi& depth, int curr, int label){
    if(cycles[curr].first==-1) {
        depth[curr] = label;
        for(auto u: adj[curr]) depth_label(adj, cycles, depth, u, label + 1);
    }
}
 
int main(){
    int n, q;
    cin >> n >> q;
    vi adj(n);
    vector<vi> pat(n);
    int logn = 32 - __builtin_clz(n);
    vector<vi> travel(logn, vi(n,-1));
    int x;
    for(int i = 0; i<n; i++){
        cin >>x;
        adj[i] = x-1;
        pat[adj[i]].push_back(i);
        travel[0][i]=x-1;
    }
    for(int i = 1; i<logn; i++) {
        for(int j = 0; j<n; j++){
            travel[i][j] = travel[i-1][travel[i-1][j]];
        }
    }
    vi parents;
    vector<pair<int,int>> cycles(n, {-1,0});
    vi status(n, 0);
    vi lcycle(n,0);
    for(int i = 0; i<n; i++){
        dfs(cycles, lcycle, status, adj, parents, i, -1, 0);
    }
    vi depth(n,0);
    for(int i = 0; i<n; i++){
        if(cycles[i].F != -1){
            for(auto a: pat[i]) depth_label(pat, cycles, depth, a, 1);
        }
    }
    int a, b;
    for(int i = 0; i<q; i++){
        cin >> a >> b; a--; b--;
        int dist = 0;
        while(depth[a]>depth[b]){
            int logf = 31 - __builtin_clz(depth[a]-depth[b]);
            dist += (1<<(logf));
            a = travel[logf][a];
        }
        if(cycles[a].F== cycles[b].F && cycles[a].F != -1){
            int pa = cycles[a].S;
            int pb = cycles[b].S;
            if(pa <= pb)dist+= pb-pa;
            else dist += lcycle[cycles[a].F]- max(pa,pb) + min(pa,pb);
            cout << dist << "\n";
        }
        else if(a==b) cout << dist << "\n";
        else cout << "-1\n";
    }
 
}