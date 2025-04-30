#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,bool> tl;
#define S second
#define F first

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector<bool> processed(n, false);
    vector<bool> cprocessed(n, false);
    vector<ll> dist(n, (ll)(1e18));
    vector<ll> cdist(n, (ll)(1e18));
    priority_queue<tl> pq;
    dist[0] = 0;
    cdist[0] = 0;
    pq.push({{0,0}, false});
    pq.push({{0,0}, true});
    while(!pq.empty()){
        tl curr = pq.top();pq.pop();
        if(processed[curr.F.S] && !curr.S) continue;
        if(cprocessed[curr.F.S] && curr.S) continue;
        processed[curr.F.S] = processed[curr.F.S] || !curr.S;
        cprocessed[curr.F.S] = cprocessed[curr.F.S] || curr.S;
        for(auto u: adj[curr.F.S]){
            if(curr.S){
                if(cdist[curr.F.S] + u.S < cdist[u.F]){
                    cdist[u.F] = cdist[curr.F.S] + u.S;
                    pq.push({{-cdist[u.F], u.F}, true});
                }
            }
            else{
                if(dist[curr.F.S] + (u.S/2) < cdist[u.F]){
                    cdist[u.F] = dist[curr.F.S] + (u.S/2);
                    pq.push({{-cdist[u.F], u.F}, true});
                }
                if(dist[curr.F.S] + u.S < dist[u.F]){
                    dist[u.F] = dist[curr.F.S] + u.S;
                    pq.push({{-dist[u.F], u.F}, false});
                }
            }
        }
    }
    cout << cdist[n-1] << "\n";
}