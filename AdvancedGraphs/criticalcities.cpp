#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int n;
vector<vi> listadj;
vector<bool> visited;
vector<bool> blocked;
stack<int> s;
vi ans;

void dfs(int c){
    vi parents(n, 0);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto e: listadj[c]){
            if(!visited[e]){
                q.push(e);
                visited[e] = true;
                parents[e] = c;
            }
        }
    }
    int curr = n-1;
    while(curr!=0){
        cout << curr << "<<\n";
        blocked[curr] = true;
        curr = parents[curr];
    }
}

void blocfs(int c){
    visited[c] = true;
    if(!blocked[c]){
        for(auto e: listadj[c]){
            if(!visited[e]){
                blocfs(e);
            }
        }
    }
    else {
        s.push(c);
    }
}

void filter() {
    int chosen = -1;
    while(!s.empty()){
        int c = s.top(); s.pop();
        for(auto e: listadj[c]){
            if(visited[e]== false) chosen = c;
        }
    }
    if(chosen != n-1 && chosen != -1) {
        ans.push_back(chosen);
        visited[chosen] = false;
        blocked[chosen] = false;
        s.push(chosen);
    }
}

int main(){
    int m; cin >> n >> m;
    int a,b;
    listadj = vector<vi>(n);

    for(int i = 0; i<m; i++){
        cin >> a >> b; a--;b--;
        listadj[a].push_back(b);
    }
    visited = vector<bool>(n, false);
    blocked = vector<bool>(n,false);
    dfs(0);
    visited = vector<bool>(n, false);
    s.push(0);
    ans.push_back(0);
    cout << blocked[1] << "\n";
    while(!s.empty()){
        cout << s.top() +1 << "<\n";
        int c = s.top(); s.pop();
        blocfs(c);
        filter();
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() + 1 << "\n";
    for(auto a: ans){
        cout << a +1 << " ";
    }
    cout << n << "\n";
}
