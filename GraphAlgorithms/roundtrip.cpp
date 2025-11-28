#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b; 
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int> colors(n,-1);
    vector<int> preds(n, -1);
    int col = 0;
    queue<int> q;
    bool possible = false;
    for(int i = 0; i<n; i++){
        if(colors[i] == -1 && !possible){
            colors[i] = col;
            q.push(i);
            while(!q.empty() && !possible){
                int curr = q.front();q.pop();
                for(auto u: adj[curr]){
                    if(colors[u]==-1){
                        colors[u] = col;
                        preds[u] = curr;
                        q.push(u);
                    }
                    else if(u != preds[curr]) {
                        possible = true;
                        map<int,int> sl;    
                        sl[curr+1] = u+1;
                        int cons = curr;
                        while(cons != i){
                            int tmp = preds[cons];
                            sl[tmp+1] = cons+1;
                            cons = tmp;
                        }
                        
                        cons = u;
                        vector<int> path;
                        path.push_back(cons+1);
                        while(!sl[cons+1]){
                            cons = preds[cons];
                            path.push_back(cons+1);
                        }
                        cons++;
                        while(cons != u+1){
                            cons = sl[cons];
                            path.push_back(cons);
                        }
                        cout << path.size() << "\n";
                        for(auto t: path){
                            cout << t << " ";
                        }
                        break;
                    }
                }
            }
        }
    }
    if(!possible) cout << "IMPOSSIBLE\n";
}