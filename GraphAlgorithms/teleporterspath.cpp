#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    int a,b;
    vi degdiff(n,0);
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        degdiff[a-1]++;
        degdiff[b-1]--;
    }
    adj[n-1].push_back(0);
    degdiff[0]--;
    degdiff[n-1]++;
    bool pos = true;
    for(int i = 0; i<n; i++) pos = pos && (degdiff[i]==0);
    if(pos){
        stack<int> call;
        deque<int> path;
        call.push(0);
        while(!call.empty()){
            int curr = call.top();
            if(adj[curr].size()==0){
                call.pop();
                path.push_front(curr);
            }
            else{
                call.push(adj[curr][adj[curr].size()-1]);
                adj[curr].pop_back();
            }
        }
        path.pop_front();
        while(path.front()!= 0 || path.back()!=n-1){path.push_back(path.front()); path.pop_front();}
        if(path.size() != m+1) cout << "IMPOSSIBLE\n";
        else{
            for(int i = 0; i<m+1;i++){
                cout << path.front() +1<< " ";
                path.pop_front();
            }
        }
    }
    else cout << "IMPOSSIBLE\n";
}