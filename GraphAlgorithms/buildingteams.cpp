#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vi colors(n,-1);
    queue<int> q;
    bool pos = true;
    for(int i = 0; i<n; i++){
        if(colors[i]==-1) {
            colors[i] = 0; 
            q.push(i);
            while(!q.empty()) {
                int curr = q.front();q.pop();
                for(auto u: adj[curr]){
                    if(colors[u] == colors[curr]) pos = false;
                    if(colors[u] == -1){
                        colors[u] = 1-colors[curr];
                        q.push(u);
                    }
                }
            }
        }
    }
    if(pos){
        for(int i = 0; i<n; i++){
            cout << colors[i] + 1 << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}