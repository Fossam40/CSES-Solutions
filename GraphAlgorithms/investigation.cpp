#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef vector<ll> vl;
typedef priority_queue<pl> pq_pl;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vp> adj(n);
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    pq_pl pq;
    pq.push({0,0});
    vector<bool> visited(n,false);
    vp dists(n, {(ll)(1e18),0});
    dists[0] = {0,0};
    while(!pq.empty()){
        ll d,s;
        tie(d,s) = pq.top();pq.pop();
        if(!visited[s]){
            dists[s].S = s;
            visited[s] = true;
            for(auto u: adj[s]){
                if(dists[s].F + u.S < dists[u.F].F){
                    dists[u.F].F = dists[s].F + u.S;
                    pq.push({-dists[u.F].F, u.F});
                }
            }
        }
    }
    vl numtrajs(n, 0);
    vl minet(n, (ll)(1e18));
    vl maxet(n, 0);
    numtrajs[0] = 1;
    minet[0] = 0;
    maxet[0] = 0;
    vp ndists(dists);
    sort(ndists.begin(), ndists.end());
    for(auto e: ndists){
        if(e.F != (ll)(1e18)){
            for(auto u: adj[e.S]){
                if((u.S + e.F) == dists[u.F].F){
                    numtrajs[u.F] = (numtrajs[u.F] + numtrajs[e.S]) % (ll)(1e9 + 7);
                    maxet[u.F] = max(maxet[u.F], maxet[e.S] + 1);
                    minet[u.F] = min(minet[u.F], minet[e.S] + 1);
                }
            }
        }
    }
    cout << dists[n-1].F << " " << numtrajs[n-1] << " " << minet[n-1] << " "<<  maxet[n-1] << "\n";
}