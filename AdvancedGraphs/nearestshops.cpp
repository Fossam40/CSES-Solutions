#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define S second
#define F first
typedef vector<ll> vl;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<vl> adj(n);
    ll a,b;
    queue<pair<pl,ll>> q;
    vector<ll> visited(n,-1);
    vector<pair<ll,ll>> novisited(n,{-1,-1});
    for(int i = 0; i<k; i++){
        cin >> a;
        q.push({{a-1,a-1},-1});
    }

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    while(!q.empty()){
        pl curr = q.front().F ;
        ll d = q.front().S; q.pop();
        for(auto u: adj[curr.F]){
            if(novisited[u].F==-1 && novisited[u].S!=curr.S && u!=curr.S){
                novisited[u].F = curr.S;
                swap(novisited[u].F, novisited[u].S);
                if(visited[u]==-1) visited[u] = d + 1;
                else visited[u] = min(visited[u], d + 1);
                q.push({{u,curr.S},d+1});
            }
        }
    }
    for(auto u: visited) cout << u + (u!=-1)<< " ";
    cout << "\n";
}