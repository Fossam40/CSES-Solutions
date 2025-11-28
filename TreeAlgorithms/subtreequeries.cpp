#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll tr[200001];

void get_depths(vector<vl> & adj, vector<bool> & visited ,vl& depths, ll curr){
    visited[curr]  = true;
    for(auto u: adj[curr]){
        if(!visited[u]){
            get_depths(adj, visited, depths, u);
            depths[curr] += depths[u];
        }
    }
}

void preord(vector<vl> & adj, vector<bool> & visited, vl& traj, int curr ){
    visited[curr] = true;
    traj.push_back(curr);
    for(auto u: adj[curr]){
        if(!visited[u]) preord(adj, visited, traj, u);
    }
}

ll get_pref(int a){
    ll ans = 0;
    while(a>=1){
        ans += tr[a];
        a -= a&(-a);
    }
    return ans;
}

ll getval(int a, int b){
    return get_pref(b) - get_pref(a-1);
}

void update(int a, ll d){
    while(a<200001){
        tr[a] += d;
        a += a&(-a);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    for(int i = 0; i<200001; i++) tr[i] = 0;
    ll t,a,b;
    vector<vl> adj(n);
    vector<bool> visited(n,false);
    vl depths(n,1);
    vl traj;
    vl revtraj(n);
    vl values(n);
    for(int i = 0; i<n; i++){
        cin >> values[i];
    }
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    get_depths(adj, visited, depths, 0);
    visited = vector<bool>(n,false);
    preord(adj, visited, traj, 0);
    for(int i = 0; i<n; i++){
        revtraj[traj[i]] = i;
    }
    for(int i = 0; i<n; i++){
        update(revtraj[i]+1, values[i]);
    }
    for(int i = 0; i<q; i++){
        cin >> t;
        if(t== 1){
            cin >> a >> b;
            ll curr = getval(revtraj[a-1]+1, revtraj[a-1]+1);
            update(revtraj[a-1]+1, b - curr);
        }
        if(t==2){
            cin >> a;
            cout << getval(revtraj[a-1]+1, depths[a-1] + revtraj[a-1]) << "\n";
        }
    }  
}

