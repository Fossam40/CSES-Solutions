#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int longuest(vector<vi> & adj, vi & succ, vi & dists, int curr){
    if(dists[curr] == -1) {
        int mdist = -1;
        for(auto u: adj[curr]){
            int prop = longuest(adj, succ, dists, u);
            if(prop>mdist){
                succ[curr] = u;
                mdist = prop;
            }
        }
        if(mdist > -1) dists[curr] = mdist + 1;
        else dists[curr] = -2;
    }
    return dists[curr];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    vi succ(n,-1);
    vi dists(n, -1);
    dists[n-1] = 0;
    longuest(adj, succ, dists, 0);
    if(dists[0]<=-1) cout << "IMPOSSIBLE\n";
    else{
        int curr = 0;
        cout << dists[0] + 1 << "\n";
        while(curr != (n-1)){
            cout << curr + 1 << " ";
            curr = succ[curr];
        }
        cout << n << "\n";
    }
}