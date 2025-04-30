#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void dfs(vector<vi> & adj, vector<bool>& visited, int curr){
    if(!visited[curr]){
        visited[curr] = true;
        for(auto u: adj[curr]){
            dfs(adj, visited, u);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n);
    vector<int> degdiff(n,0);
    int a,b;
    map<pair<int,int>, int> used;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        degdiff[a-1]++;
        degdiff[b-1]++;
    }
    vector<bool> visited(n,false);
    dfs(adj, visited, 0);
    int blocked = 0;
    bool pos = true;
    for(int i = 0; i<n; i++){
        pos = pos && (((degdiff[i]%2)==0) && (visited[i]||degdiff[i]==0));
        blocked += (adj[i].size()==0);
    }
    if(pos){
        deque<int> path;
        path.push_back(0);
        while(blocked != n){
            int curr = path.back();
            while(adj[curr].size() != 0){
                while((adj[curr].size()!= 0) && (used[{adj[curr][(adj[curr]).size()-1], curr}]==2)){
                    adj[curr].pop_back();
                }
                if(adj[curr].size() != 0){
                    if(adj[curr].size() == 1){
                        blocked++;
                    }
                    int next = adj[curr][(adj[curr]).size()-1];
                    used[{curr, next}] = 2;
                    adj[curr].pop_back();
                    curr = next;
                    path.push_back(next);
                }
                else {blocked++;}
            }
            if(blocked !=n){
                while(adj[path.back()].size() == 0){path.push_front(path.back());path.pop_back();}
            }
        }
        cout << "\n";
        while(path.back()!= 0 || path.front()!=0){path.push_front(path.back());path.pop_back();}
        while(!path.empty()){
            cout << path.front()+1 << " ";
            path.pop_front();
        }
    }
    else cout << "IMPOSSIBLE\n";
}