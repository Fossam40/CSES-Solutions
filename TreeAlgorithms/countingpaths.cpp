#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define F first
#define S second
typedef pair<ll,ll> pl;

ll parent(vl & dsu, int a){
    if(dsu[a]==a) return a;
    else{
        ll ans = parent(dsu, dsu[a]);
        dsu[a] = ans;
        return ans;
    }
}

void unite(vl & dsu, int s, int p){
    dsu[parent(dsu, s)] = parent(dsu, p);
}

void getpars(vector<vl> & adj, vector<bool> & visited, vl& parents, int curr){
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            parents[u] = curr;
            getpars(adj, visited, parents, u);
        }
    }
}

void breakpaths(vector<vl> & adj, vector<bool> & visited, vector<vl> & q, vl & fq, vl & dp, vl & parents, vl & dsu, ll curr){
    visited[curr] = true;
    for(auto u: q[curr]){
        if(visited[u]){
            ll lca = parent(dsu, u);
            dp[lca]--;
            if(lca!=0)fq[parents[lca]] -= 2;
            fq[u]++;
            fq[curr]++;
        }
    }
    for(auto u: adj[curr]){
        if(!visited[u]){
            breakpaths(adj, visited, q, fq, dp, parents, dsu, u);
        }
    }
    unite(dsu, curr ,parents[curr]);
}

ll solve(vector<vl> & adj, vector<bool> & visited,vl& fq, vl& dp, ll curr){
    ll curropen = fq[curr];
    visited[curr] = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            curropen += solve(adj, visited, fq, dp, u);
        }
    }
    dp[curr] += curropen;
    return curropen;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, r; cin >> n >> r;
    ll a,b;
    vector<vl> adj(n);
    vector<vl> q(n);
    vl fq(n,0);
    vl depth(n,0);
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    vl parents(n);
    getpars(adj, visited, parents, 0);
    vector<ll> dp(n,0);
    for(int i = 0; i<r; i++){
        cin >> a >> b;
        if(a!= b){
            q[a-1].push_back(b-1);
            q[b-1].push_back(a-1);
        }
        else q[a-1].push_back(b-1);
    }
    vl dsu(n);
    for(int i = 0; i<n; i++){
        dsu[i] = i;
        visited[i] = false;
    }
    breakpaths(adj, visited, q, fq, dp, parents, dsu, 0);
    visited = vector<bool>(n,false);
    solve(adj, visited, fq, dp, 0);
    for(auto a: dp) cout << a << " ";
    cout << "\n";
}