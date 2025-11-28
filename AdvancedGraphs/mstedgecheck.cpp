#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second


typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
priority_queue<pair<int,pi>> pq;
vector<vpi> listadj;
vector<vpi> treeadj;
vector<vi> binlift;
vector<vi> maxlift;
vi parents;
vi depths;
int nbparts;
int n;

int get_parent(int a) {
    if(a == parents[a]) return a;
    int ans = get_parent(parents[a]);
    parents[a] = ans;
    return ans;
}

bool join(int a, int b){
    int par1 = get_parent(a);
    int par2 = get_parent(b);
    if(par1 != par2) {
        parents[par1] = par2;
        nbparts--;
    }
    return (par1 != par2);
}

void build_tree(){
    while(nbparts>1){
        auto elt = pq.top(); pq.pop();
        if(join(elt.S.F, elt.S.S)){
            treeadj[elt.S.F].push_back({elt.S.S, -elt.F});
            treeadj[elt.S.S].push_back({elt.S.F, -elt.F});
        }
    }
}

void root_tree(int c, int p) {
    for(auto a: treeadj[c]){
        if(a.F!=p){
            depths[a.F] = depths[c] + 1;
            root_tree(a.F,c);
            maxlift[0][a.F] = a.S;
            binlift[0][a.F] = c;
        }
    }
}

void iterate_lift() {
    for(int i = 1; i<30; i++) {
        for(int j = 0; j<n; j++){
            if(binlift[i-1][j] != -1){
                binlift[i][j] = binlift[i-1][binlift[i-1][j]];
                maxlift[i][j] = max(maxlift[i-1][j], maxlift[i-1][binlift[i-1][j]]);
            }
            else{
                binlift[i][j] = -1;
            }
        }
    }
}

int query(int a, int b) {
    int ans = 0;
    if(depths[a]>depths[b]) swap(a,b);
    int j = 29;
    while(depths[b]>depths[a]){
        while((binlift[j][b] != -1) && depths[binlift[j][b]]>=depths[a]){
            ans = max(ans, maxlift[j][b]);
            b = binlift[j][b];
        }
        j--;
    }
    if(a!=b){
        for(j = 29;j>=0; j--){
            while(binlift[j][a]!=binlift[j][b]){
                ans = max(ans, max(maxlift[j][b], maxlift[j][a]));
                a = binlift[j][a];
                b = binlift[j][b];
            }
        }
        ans = max(ans, max(maxlift[0][b], maxlift[0][a]));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> n >> m;
    int a,b,c;
    listadj = vector<vpi>(n);
    treeadj= vector<vpi>(n);
    binlift = vector<vi>(30, vi(n,0));
    maxlift =  vector<vi>(30, vi(n,0));
    depths = vi(n, 0);  
    parents = vi(n);
    vector<pair<int,pi>> edges;
    nbparts = n;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        listadj[a-1].push_back({b-1,c});
        listadj[b-1].push_back({a-1,c});
        pq.push({-c, {a-1, b-1}});
        edges.push_back({c,{a-1,b-1}});
    }
    for(int i = 0; i<n; i++) parents[i] = i;
    build_tree();
    binlift[0][0] = -1;
    root_tree(0,-1);
    iterate_lift();
    for(int i = 0; i<m; i++){
        if(query(edges[i].S.F, edges[i].S.S)>=edges[i].F) cout << "YES\n";
        else cout << "NO\n";
    }

}





