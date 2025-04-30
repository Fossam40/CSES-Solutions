#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,pair<ll,ll>> pl;
typedef vector<pl> vp;
#define F first
#define S second

int getparent(vi& parts, int a) {
    int ans = parts[a];
    if(ans != a){
        int parent = getparent(parts, ans);
        parts[a] = parent;
        return parent;
    }
    else return ans;
}

bool unite(vi& parts, int a, int b){
    int par1 = getparent(parts, a);
    int par2 = getparent(parts, b);
    parts[par1] = par2;
    return par1!=par2;
}

int main() {
    int n,m;
    cin >> n >> m;
    vp adj(n);
    ll a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj.push_back({c,{a-1,b-1}});
    }
    sort(adj.begin(), adj.end());
    vi parts(n);
    int nbp = n;
    ll cost = 0;
    for(int i = 0; i<n; i++) parts[i] = i;
    int j = 0;
    while(nbp > 1 && j<(adj.size())){
        if(unite(parts, adj[j].S.F, adj[j].S.S)) {
            nbp--;
            cost += adj[j].F;
        }
        j++;
    }
    if(nbp == 1) cout << cost << "\n";
    else cout << "IMPOSSIBLE\n";

}