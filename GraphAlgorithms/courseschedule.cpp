#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

bool toposort(vector<vi> & adj, vi & states, stack<int> & order, int current){
    for(auto u: adj[current]){
        if(states[u]==1) return false;
        if(states[u] == 0){
            states[u]++;
            if(!(toposort(adj, states, order, u))) return false;
        }
    }
    order.push(current);
    states[current] = 2;
    return true;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    for(int i = 0; i<m;i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    bool pos = true;
    vi states(n,0);
    stack<int> order;
    int i = 0;
    while(i<n && pos){
        if(states[i] == 0){
            states[i]++;
            pos = toposort(adj, states, order, i);
        }
        i++;
    }
    if(pos){
        while(!order.empty()){
            cout << order.top() +1 << " ";
            order.pop();
        }
    }
    else cout << "IMPOSSIBLE\n";
}