#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
vector<vector<pi>> listadj;
vector<vector<int>> nlistadj;
vector<bool> visited;
int n;

void dfs(int curr, int p){
    visited[curr] = true;
    for(auto a: listadj[curr]){
        if(visited[a.F] && (a.S >= 0) && a.F != p){
            nlistadj[curr].push_back(a.F);
            listadj[a.F][a.S].S = -1;
        }
        if(!visited[a.F] && (a.S >= 0) && a.F != p){
            dfs(a.F,curr);
        }
    }
    if(p!= -1){
        if(nlistadj[curr].size()%2){
            nlistadj[curr].push_back(p);
        }
        else{
            nlistadj[p].push_back(curr);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    visited = vector<bool>(n, false);
    listadj = vector<vector<pi>>(n);
    nlistadj =vector<vector<int>>(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b; a--; b--;
        listadj[a].push_back({b,listadj[b].size()});
        listadj[b].push_back({a,listadj[a].size() - 1});
    }
    bool pos = true;
    for(int i = 0; i<n; i++){
        if(!visited[i]) dfs(i, -1);
        pos = pos && ((nlistadj[i].size() % 2) == 0);
    }
    if(pos){
        for(int i = 0; i<n; i++){
            for(auto e: nlistadj[i]){
                cout << i+1 << " " <<e+1 << "\n";
            }
        }
    }
    else cout << "IMPOSSIBLE\n";

}