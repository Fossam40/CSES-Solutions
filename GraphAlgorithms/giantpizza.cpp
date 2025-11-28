#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void topsort(vector<vi> & adj, vector<bool>& visited, stack<int>& order, int curr){
    if(!visited[curr]){
        visited[curr] =true;
        for(auto u: adj[curr]){
            topsort(adj,visited, order, u);
        }
        order.push(curr);
    }
}

void dfs(vector<vi> & adj, vector<bool>& visited, vi& component, int curr, int ccomp){
    if(!visited[curr]){
        visited[curr] =true;
        component[curr] = ccomp;
        for(auto u: adj[curr]){
            dfs(adj,visited, component, u, ccomp);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int a,b;
    cin >> n >>m;
    char sa, sb;
    vector<vi> adj(2*m);
    vector<vi> madj(2*m);
    for(int i = 0; i<n; i++){
        cin >> sa >> a >> sb >> b;
        adj[a-1 + m*(sa == '-')].push_back(b-1 + m*(sb == '+'));
        adj[b-1 + m*(sb == '-')].push_back(a-1 + m*(sa == '+'));

        madj[b-1 + m*(sb == '+')].push_back(a-1 + m*(sa == '-'));
        madj[a-1 + m*(sa == '+')].push_back(b-1 + m*(sb == '-'));
    }
    vector<bool> visited(2*m, false);
    stack<int> order;
    for(int i = 0; i<2*m; i++) topsort(madj, visited, order, i);
    visited = vector<bool>(2*m,false);
    int ccomp = 0;
    vector<int> component(2*m,0);
    for(int i = 0; i<2*m; i++){   
        int curr = order.top();order.pop();
        ccomp += !visited[curr];
        dfs(adj, visited, component, curr, ccomp);
    }
    bool pos = true;
    for(int i = 0; i<m; i++){
        if(component[i]==component[i+m]){
            pos = false;
        }
    }
    if(pos){
        vector<vi> compadj(ccomp);
        vector<vi> members(ccomp);
        for(int i = 0; i<(2*m); i++){
            members[component[i]-1].push_back(i);
            for(auto u: madj[i]){
                compadj[component[i]-1].push_back(component[u]-1);
            }
        }
        stack<int> comporder;
        visited = vector<bool>(ccomp,false);
        for(int i = 0; i<ccomp; i++) topsort(compadj, visited, comporder, i);
        vector<int> val(m,-1);
        for(int i = 0; i<ccomp; i++){
            int curr = comporder.top();comporder.pop();
            for(auto u: members[curr]){
                if(u>=m && val[u-m]==-1) val[u-m]=2;
                else if(u<m && val[u]==-1) val[u]=1;
            }
        }
        for(auto u: val){
            if(u==1) cout << "- ";
            else cout << "+ ";
        }
    }
    else cout << "IMPOSSIBLE\n";
}