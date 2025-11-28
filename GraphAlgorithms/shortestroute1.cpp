#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vi;
#define F first
#define S second

int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b,c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1,c});
    }
    priority_queue<pl> q;
    q.push({0,0});
    vector<ll> distances(n, -1);
    while(!q.empty()){
        pl curr = q.top();q.pop();
        if(distances[curr.S] == -1){
            distances[curr.S]= -curr.F;
            for(auto u: adj[curr.S]){
                if(distances[u.F] == -1){
                    q.push({-(distances[curr.S] + u.S), u.F});
                }
            }
        }
    }
    for(auto u: distances){
        cout << u << " ";
    }
}