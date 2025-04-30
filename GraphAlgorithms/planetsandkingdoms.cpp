#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void topsort(vector<vi> & adj, vector<bool> & visited, stack<int> &order, int curr){
    if(!visited[curr]){
        visited[curr] = true;
        for(auto u: adj[curr]){
            topsort(adj, visited, order, u);
        }
        order.push(curr);
    }
}

void findcomp(vector<vi> & adj, vector<bool> & visited, vi & comps, int curr, int currcomp){
    if(!visited[curr]){
        visited[curr] = true;
        comps[curr] = currcomp;
        for(auto u: adj[curr]) {findcomp(adj, visited, comps, u, currcomp);}
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<vi> madj(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        madj[b-1].push_back(a-1);
    }
    vector<bool> visited(n,false);
    stack<int> order;
    for(int i = 0; i<n; i++) topsort(adj, visited, order, i);
    vector<int> comps(n,0);
    int currcomp = 0;
    visited = vector<bool>(n,false);
    for(int i = 0; i<n; i++){
        int curr = order.top();order.pop();
        if(!visited[curr]){
            currcomp++;
            findcomp(madj, visited, comps, curr, currcomp);
        }
    }
    cout << currcomp << "\n";
    for(auto u: comps) cout << u << " ";
}