#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll,ll> pl;
typedef vector<pl> vl;

bool dcycle(vector<vl> & adj, vector<ll> & di, vector<bool> & fromt){
    di[0] = 0;
    for(int i = 1; i<adj.size(); i++){
        for(int j = 0; j< adj.size(); j++){
            for(auto u: adj[j]){
                if(di[j] != (ll)(-1e18)) di[u.F]= max(di[j]+u.S, di[u.F]);
            }
        }
    }
    bool caninf = false;
    for(int j = 0; j<adj.size(); j++){
        for(auto u: adj[j]){
            if((di[j]+u.S > di[u.F]) && fromt[u.F] && di[j]!=(ll)(-1e18)) {caninf = true;}
        }
    }
    return caninf;
}

void badfs(vector<vl> & adj, vector<bool>& fromt, int n){
    for(auto u: adj[n]){
        if(!fromt[u.F]){
            fromt[u.F] = true;
            badfs(adj, fromt, u.F);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vl> adj(n);
    vector<vl> revadj(n);
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
        revadj[b-1].push_back({a-1,c});
    }
    vector<bool> fromt(n);
    fromt[n-1] = true;
    badfs(revadj, fromt, n-1);
    vector<ll> states(n,(ll)(-1e18));
    if(dcycle(adj, states,fromt)) cout << "-1\n";
    else{
        cout << states[n-1] << "\n";
    }
}