#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vv;

void add_edge(vv & adj, int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int main(){
    int n,m;
    cin >> n >> m;
    vv adj(n*m);
    string s, p;
    p = string(m, '#');
    int start;
    int end;
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] != '#'){
                if(j>0 && s[j-1] != '#') add_edge(adj, i*m + j, i*m + j -1);
                if(i>0 && p[j] != '#') add_edge(adj, i*m + j, (i-1)*m + j);
            }
            if(s[j]=='A') start = i*m + j;
            if(s[j]=='B') end = i*m + j;
        }
        p = s;
    }
    vector<bool> visited(n*m, false);
    vector<int> parent(n*m,-1);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto u: adj[curr]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
                parent[u] = curr;
            }
        }
    }
    if(visited[end]){
        cout << "YES\n";
        stack<char> p;
        int curr = end;
        while(curr != start){
            if(parent[curr] == curr - m) p.push('D');
            else if(parent[curr] == curr + m) p.push('U');
            else if(parent[curr] == curr - 1) p.push('R');
            else if(parent[curr] == curr +1) p.push('L');
            curr = parent[curr];
        }
        cout << p.size() << "\n";
        while(!p.empty()){
            cout << p.top();
            p.pop();
        }
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }
}