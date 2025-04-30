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

bool unite(vi& parts, vi & size, int a, int b){
    int par1 = getparent(parts, a);
    int par2 = getparent(parts, b);
    if(size[par1]<size[par2]) swap(par1, par2);
    parts[par2] = par1;
    if(par1 != par2) size[par1] += size[par2];
    return (par1!=par2);
}

int main() {
    int n, m;
    ll a,b;
    cin >> n >> m;
    vp adj;
    vi parts(n);
    int nbcomp = n;
    int msize = 1;
    for(int i = 0; i<n; i++) parts[i] = i;
    vi size(n,1);
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        nbcomp -= unite(parts, size, a-1, b-1);
        msize = max(msize, max(size[getparent(parts, a-1)], size[getparent(parts,b-1)]));
        cout << nbcomp << " "<< msize <<"\n";
    }
}