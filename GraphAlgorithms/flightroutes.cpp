#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define F first
#define S second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vp> adj(n);
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    priority_queue<pl> pq;
    vector<int> nvis(n, 0);
    pq.push({0,0});
    int p = 0;
    while(!pq.empty() && p<k){
        ll d, s;
        tie(d,s) = pq.top(); pq.pop();
        if(nvis[s]<k){
            nvis[s]++;
            if(s == (n-1)) {cout << - d << " ";p++;}
            for(auto u: adj[s]){
                if(nvis[u.F] < k){
                    pq.push({d- u.S, u.F});
                }
            }
        }
    }
}