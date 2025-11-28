#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define F first
#define S second
typedef pair<int,int> pi;
int nbparts,q;
vi parts;
stack<int> s;
set<pi> edges;


int get_parent(int a){
    if(parts[a]==a) return a;
    else{
        int ans = get_parent(parts[a]);
        parts[a] = ans;
        return ans;
    }
}


void join(int a, int b) {
    int par1 = get_parent(a);
    int par2 = get_parent(b);
    if(par1!= par2){
        nbparts--;
    }
    parts[par1] = par2;
}

void solve(int p) {
    int a,b;
    cin >> a >> b;a--;b--;
    if(a>b) swap(a,b);
    edges.erase({a,b});
    if(p==q-1){
        for(auto e: edges){
            join(e.F, e.S);
        }
        s.push(nbparts);
        join(a,b);
    }
    else {
        solve(p+1);
        s.push(nbparts);
        join(a,b);
    }
}

int main() {
    int n,m; cin >> n >> m >> q;
    parts = vi(n);
    for(int i = 0; i<n; i++) parts[i] = i;
    int a,b;
    nbparts = n;
    for(int i = 0; i<m; i++){
        cin >> a >> b;a--;b--;
        edges.insert({min(a,b), max(a,b)});
    }
    solve(0);
    while(!s.empty()){
        cout << s.top() << " "; s.pop();
    }
    cout << "\n";
}