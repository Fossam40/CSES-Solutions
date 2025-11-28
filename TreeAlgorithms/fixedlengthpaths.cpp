#include <bits/stdc++.h>
using namespace std;
#define S second
#define C (int)1e9
#define F first
typedef pair<int,int> pi;
typedef vector<int> vi;
int n, cent = -1;
vector<bool> marked;
vector<vi> adj;
long long ans = 0;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
void dfs_size(int c, int p){
    if(marked[c]) return;
    n+=1;
    for(auto e: adj[c]){
        if(e!=p) dfs_size(e,c);
    }
}
 
int dfs_centroid(int c, int p){
    if(marked[c]) return 0;
    int child = 1;
    bool ok = true;
    for(auto e: adj[c]){
        if(cent != -1) break;
        if(e!=p){
            int res = dfs_centroid(e, c);
            if(res > (n/2)) ok = false;
            child += res;
        }
    }
    if((n - child)> n/2) ok = false;
    if((cent == -1) && ok) cent = c;
    return child;
}
 
int bin_index(vi & arr, int val){
    int k = -1;
    for(int i = arr.size(); i>0; i/=2){
        while((k+i)<arr.size() && arr[k+i]<=val) k+=i;
    }
    return k;
}
 
long long calc_aux(vi& all, vector<vi> & subparts, int q){
    long long tmp = bin_index(all, q) + 1;
    for(auto a: subparts){
        for(auto e: a){
            tmp += bin_index(all, q-e) + 1;
            tmp -= bin_index(a, q-e) + 1;
        }
    }
    return tmp/2;
}
 
void calculate(int c, int q){
    if(n<q) return;
    vector<vi> subtrees(adj[c].size());
    queue<pair<pi,int>> s;
    stack<int> qa;
    vi dist(n+1,0);
    dist[0]=1;
    for(int i = 0; i<adj[c].size(); i++){
        int e = adj[c][i];
        if(!marked[e]) s.push({{e,c},1});
        while(!s.empty()){
            auto elt = s.front(); s.pop();
            if(elt.S > q) break;
            qa.push(elt.S);
            if(q-elt.S>=0 && (q-elt.S) < n) ans += dist[q-elt.S];
            for(auto e: adj[elt.F.F]){
                if(!marked[e]){
                    if(e!= elt.F.S){
                        s.push({{e,elt.F.F},elt.S+ 1});
                    }
                }
            }
        }
        while(!s.empty()) s.pop();
        while(!qa.empty()){
            dist[qa.top()]++;
            qa.pop();
        }
    }
}
 
 
 
void solve(int c, int q){
    if(marked[c]) return;
    n = 0; cent = -1;
    dfs_size(c,-1);
    dfs_centroid(c, -1);
    marked[cent] = true;
    calculate(cent, q);
    for(auto e: adj[cent]){
        solve(e,q);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int q; cin >> q;
    int a,b;
    adj = vector<vi>(n);
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    marked = vector<bool>(n,false);
    solve(0,q);
    cout << ans << "\n";
}