#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define C 1000000000
typedef pair<int,int> pi;
int n;
vector<vector<int>> listadj;

int bfs(int start){
    vector<int> visited(n,-1);
    queue<pair<pi,int>> q;
    q.push({{start,-1},0});
    int minc = C;
    while(!q.empty()){
        int c,p;
        tie(c,p) = q.front().F;
        if(visited[c]==-1) {
            visited[c]=q.front().S;
            for(auto e: listadj[c]){
                if(e != p){
                    if(visited[e]!=-1) {
                        minc = min(minc, q.front().S+visited[e] + 1);
                    }
                    q.push({{e,c},q.front().S+1});
                }
            }
        }
        q.pop();
    }
    return minc;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> n >> m;
    listadj = vector<vector<int>>(n);
    for(int i = 0; i<m; i++){
        int a,b; cin >> a >> b;
        listadj[a-1].push_back(b-1);
        listadj[b-1].push_back(a-1);
    }
    int minf = C;
    for(int i = 0; i<n; i++){
      minf = min(minf, bfs(i));
    } 
    if(minf==C) cout << "-1\n";
    else cout << minf << "\n";
}