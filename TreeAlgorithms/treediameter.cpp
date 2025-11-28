#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define F first
#define S second
typedef pair<int,int> pi;

pi furthest(vector<vi> & adj, int curr) {
    pi ans = {0,0};
    queue<pi> q;
    q.push({curr,0});
    vector<bool> visited(adj.size(),false);
    while(!q.empty()){
        int c,d;
        tie(c,d) = q.front(); q.pop();
        if(!visited[c]){
            visited[c] = true;
            if(ans.S < d) ans = {c,d};
            for(auto u: adj[c]) q.push({u,d+1});
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int x,y;
    vector<vi> adj(n);
    for(int i = 1 ; i<n; i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    cout << furthest(adj, furthest(adj,0).F).S << "\n";
}