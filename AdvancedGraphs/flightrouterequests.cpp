#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second

stack<int> st;
vector<int> visited;
int n,m;
vector<vector<int>> listadj;
bool loop;
int numed;
int condloop;
vector<pair<int,bool>> parts;

int get_parent(int a){
    if(parts[a].F==a) return a;
    else{
        int ans = get_parent(parts[a].F);
        parts[a].F = ans;
        return ans;
    }
}


void join(int a, int b) {
    int par1 = get_parent(a);
    int par2 = get_parent(b);
    parts[par1].F = par2;
    parts[par2].S = parts[par1].S || parts[par2].S;
}

void topo(int s){
    visited[s] = 0;
    for(auto e: listadj[s]){
        if(visited[e]==1) topo(e);
    }
    st.push(s);
}
 
void solve(int c, int par){
    visited[c] = 1;
    join(c,par);
    for(auto e: listadj[c]){
        if(visited[e] == 1) {
            loop = true;
            parts[get_parent(c)].S = true;
        }
        else if(visited[e] == 0){
            numed++;
            solve(e, par);
        }
        else if(visited[e]==2){
            int myp = get_parent(c);
            int otherp = get_parent(e);
            if((myp != otherp) && !parts[otherp].S) numed++;
            else if((myp != otherp)) condloop++;
            join(myp, otherp);
        }
    }
    visited[c] = 2;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    visited = vector<int>(n, 1);
    listadj = vector<vector<int>>(n);
    parts = vector<pair<int,bool>>(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        listadj[a-1].push_back(b-1);
    }
    for(int i = 0; i<n; i++){
        if(visited[i]==1) topo(i);
        parts[i].F = i;
        parts[i].S = false;
    }
    int ans = 0;
    while(!st.empty()){
        int curr = st.top(); st.pop();
        loop = false;
        numed = 0;
        condloop = 0;
        solve(curr, curr);
        ans += (loop + numed) + condloop*(!loop);
    }
    cout << ans << "\n";
}