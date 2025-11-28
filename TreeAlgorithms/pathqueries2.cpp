#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N = 200001;
int t[2*N] = {0};
int num = 0;
int n;

void build() {
    for(int i = n-1; i>0; i--) t[i] = max(t[i<<1],t[i<<1|1]);
}

void update(int pos, int val){
    for(t[pos+=n] = val; pos>1; pos>>=1) t[pos>>1] = max(t[pos], t[pos^1]);
}

int query(int l, int r){
    int ans = 0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) ans = max(ans, t[l++]);
        if(r&1) ans = max(ans, t[--r]);
    }
    return ans;
}

int heavy_light(vector<vi> & adj, vector<bool>& visited, vi& depths, vi & child, int curr){
    visited[curr] = true;
    int subs = 0;
    int msize = -1;
    int hson = -1;
    for(auto u: adj[curr]){
        if(!visited[u]){
            depths[u] = depths[curr] +1;
            int cand = heavy_light(adj, visited, depths, child, u);
            if(cand>msize){
                msize = cand;
                hson = u;
            }
            subs += cand;
        }
    }
    child[curr] = hson;
    return subs;
}

int find(vi & depths, vi & numbering, vi& heav_par, vi & parents, int a, int b){
    int ans = 0;
    while(heav_par[a] != heav_par[b]){
        if(depths[heav_par[a]] < depths[heav_par[b]]) swap(a,b);
        ans = max(ans, query( numbering[heav_par[a]], numbering[a] + 1));
        a = parents[heav_par[a]];
    }
    if(depths[a]> depths[b]) swap(a,b);
    ans = max(ans, query(numbering[a], numbering[b] + 1));
    return ans;
}

void number(vector<vi> &adj, vector<bool> & visited, vi& child, vi & heav_par, vi & numbering, vi& parents, int curr){
    visited[curr] = true;
    if(child[curr] != -1) heav_par[child[curr]] = heav_par[curr];
    numbering[curr] = num++;
    if(child[curr]!=-1) {
        parents[child[curr]] = curr;
        number(adj, visited, child, heav_par, numbering, parents, child[curr]);
    }
    for(auto u: adj[curr]){
        if(!visited[u]){
            parents[u] = curr;
            number(adj, visited, child, heav_par, numbering, parents, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    vector<int> values(n);
    for(int i = 0; i<n; i++){
        cin >> values[i];
    }
    int a,b,ty;
    vector<vector<int>> adj(n);
    for(int i = 0; i<(n-1); i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<bool> visited(n);
    vector<int> depths(n);
    vector<int> child(n,-1);
    vector<int> heav_par(n);
    for(int i = 0; i<n; i++) heav_par[i] = i;
    heavy_light(adj, visited, depths, child, 0);

    visited = vector<bool>(n,false);
    vector<int> numbering(n,0);
    vi parents(n,0);
    number(adj, visited, child, heav_par, numbering, parents, 0);

    for(int i = 0; i<n; i++){
        t[numbering[i] + n] = values[i];
    }
    build();
    for(int i = 0; i<q; i++){
        cin >> ty >> a >> b;
        if(ty==1){
            update(numbering[a-1], b);
        }
        else {
            cout << find(depths, numbering, heav_par, parents, a-1, b-1) << " ";
        }
    }
    cout << "\n";
    return 0;
}
