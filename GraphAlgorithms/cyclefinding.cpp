#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define S second
#define F first

int main(){
    int n,m;
    cin >> n >> m;
    ll a,b,c;
    vector<vp> adj(n);
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    vector<ll> pred(n,-1);
    vector<ll> dists(n,(ll)(1e18));
    dists[0] = 0;
    for(int i = 0; i<(n-1); i++){
        for(int j=0; j<n; j++){
            for(auto u: adj[j]){
                if((dists[j] + u.S)< dists[u.F]){ 
                    dists[u.F] = dists[j] + u.S;
                    pred[u.F] = j;
                }
            }
        }
    }
    int i = 0;
    int done = false;
    int start;
    while(i<n && !done){
        for(auto u: adj[i]){
            if((dists[i] + u.S)< dists[u.F]){ 
                dists[u.F] = dists[i] + u.S;
                pred[u.F] = i;
                done = true;
                start = u.F;
            }
        }
        i++;
    }
    if(done){
        cout << "YES\n";
        vector<bool> seen(n,false);
        stack<int> path;
        path.push(start);
        while(!seen[start]){
            seen[start] = true;
            start = pred[start];
            path.push(start);
        }
        cout << start +1<< " "; path.pop();
        while(path.top() != start){
            cout << path.top() +1<< " ";
            path.pop();
        }
        cout << start+1<< "\n";
    }
    else{
        cout << "NO\n";
    }
}