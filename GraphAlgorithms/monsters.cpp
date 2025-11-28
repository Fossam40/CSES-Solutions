#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define S second
#define F first

void add_edge(vector<vi> & t, int a, int b){
    t[a].push_back(b);
    t[b].push_back(a);
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, p;
    p = string(m, '#');
    queue<pi> q;
    vector<vi> adj(n*m);
    vi mDist(n*m, -1);
    int start;
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] != '#'){
                if(j>0 && s[j-1] != '#') add_edge(adj, i*m + j, i*m + j - 1);
                if(i>0 && p[j] != '#') add_edge(adj, i*m + j, (i-1)*m + j);
                if(s[j] == 'M') {q.push({i*m + j, 0}); mDist[i*m + j]=0;}
                if(s[j] == 'A') start = i*m + j;
            }
        }
        p = s;
    }
    while(!q.empty()){
        pi curr = q.front();q.pop();
        for(auto u: adj[curr.F]){
            if(mDist[u] == -1){
                mDist[u] = curr.S + 1;
                q.push({u, curr.S + 1});
            }
        }
    }
    vi ancestors(m*n, -1);
    q.push({start, 0});
    int end = -1;
    if(start<m || start>=((n-1)*m) || (start%m == (m-1)) || (start%m == 0)) end = start;
    while(!q.empty()){
        pi curr = q.front();q.pop();
        for(auto u: adj[curr.F]){
            if(ancestors[u] == -1 && ((curr.S+1)<mDist[u] || mDist[u]==-1)){
                if(u<m || u>=((n-1)*m) || (u%m == (m-1)) || (u%m == 0)) end = u;
                ancestors[u] = curr.F;
                q.push({u,curr.S + 1});
            }
        }
    }
    if(end != -1){
        cout << "YES\n";
        int curr = end;
        stack<char> s;
        while(curr != start){
            if(ancestors[curr] == curr - m) s.push('D');
            else if(ancestors[curr] == curr + m) s.push('U');
            else if(ancestors[curr] == curr - 1) s.push('R');
            else if(ancestors[curr] == curr + 1) s.push('L');
            curr = ancestors[curr];
        }
        int l = s.size();
        cout << l << "\n";
        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
        if(l!= 0) cout << "\n";
    }
    else cout << "NO\n";
}