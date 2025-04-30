#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    for(int i = 0; i<m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    queue<int> q;
    vector<bool> visited(n, false);
    vi ancestors(n,-1);
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(auto u: adj[curr]){
            if(!visited[u]){
                visited[u] = true;
                ancestors[u] = curr;
                q.push(u);
            }
        }
    }
    if(visited[n-1]){
        stack<int> p;
        int curr = n-1;
        while(curr != 0){
            p.push(curr);
            curr = ancestors[curr];
        }
        p.push(0);
        cout << p.size() << "\n";
        while(p.size() != 1){
            cout << p.top() + 1 << " ";
            p.pop();
        }
        cout << p.top() + 1 << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}