#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
vector<pl> parts;
ll transfersum;

int getparent(int a){
    if(parts[a].F == a) return a;
    else{
        int ans = getparent(parts[a].F);
        parts[a].F = ans;
        return ans;
    }
}

void join(int a, int b){
    int par1 = getparent(a);
    int par2 = getparent(b);
    if(par1 != par2){
        parts[par2].F = par1;
        parts[par1].S += parts[par2].S;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    parts = vector<pl>(n);
    transfersum = 0;
    vector<pair<int,pl>> edges(n-1);
    for(int i = 0; i<n; i++) parts[i] = {i,1};
    for(int i =0; i<n-1; i++){
        cin >> edges[i].S.F >> edges[i].S.S >> edges[i].F;
    }
    sort(edges.rbegin(), edges.rend());
    for(int i = 0; i<n-1; i++){
        int par1 = getparent(edges[i].S.F);
        int par2 = getparent(edges[i].S.S);
        transfersum += parts[par1].S*parts[par2].S*edges[i].F;
        join(par1,par2);
    }
    cout << transfersum << "\n";
}