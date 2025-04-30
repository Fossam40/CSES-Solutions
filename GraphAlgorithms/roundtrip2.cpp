#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void printpath(vi & preds, int start, int curr, int len){
    if(curr != start){
        printpath(preds, start, preds[curr], len + 1);
        cout << curr+1 << " ";
    }
    else {
        cout << len +1<< "\n";
        cout << start+1 << " ";
    }
    
}

int dfs(vector<vi> & adj, vi & states, vi & preds, int curr){
    if(states[curr] == 0){
        states[curr]++;
        for(auto u: adj[curr]){ 
            if(states[u]==0){
                preds[u] = curr;
                int res = dfs(adj, states, preds, u);
                if(res!=-1) return res;
            }
            else if(states[u]==1){
                preds[u] = curr; return u;
            }
        }
    }
    states[curr] = 2;
    return -1;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    vi states(n, 0);
    vi preds(n);
    int i = 1;
    int start = dfs(adj, states, preds, 0);
    while(i<n && (start == -1)){
        if(states[i] == 0){
            start = dfs(adj, states, preds, i);
        }
        i++;
    }
    if(start != -1){
        printpath(preds, start, preds[start], 1);
        cout << start +1<< "\n";
    }
    else cout << "IMPOSSIBLE\n";
}