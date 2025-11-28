#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define C (1e6)

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
vector<vi> treeadj;
vector<vi> binlift;
vector<vi> minlift;
vi dist;
vi depths;
int n;
queue<pi> qu;

void root_tree(int c, int p) {
    for(auto a: treeadj[c]){
        if(a!=p){
            binlift[0][a] = c;
            minlift[0][a] = dist[c];
            depths[a] = depths[c] + 1;
            root_tree(a,c);
        }
    }
}

void iterate_lift() {
    for(int i = 1; i<30; i++) {
        for(int j = 0; j<n; j++){
            if(binlift[i-1][j] != -1){
                binlift[i][j] = binlift[i-1][binlift[i-1][j]];
                minlift[i][j] = min(minlift[i-1][j], minlift[i-1][binlift[i-1][j]]);
            }
            else{
                binlift[i][j] = -1;
            }
        }
    }
}

int query(int a, int b) {
    int ans = min(dist[a], dist[b]);
    int suma = depths[a] + depths[b];
    if(depths[a]>depths[b]) swap(a,b);
    int j = 29;
    while(depths[b]>depths[a]){
        while((binlift[j][b] != -1) && depths[binlift[j][b]]>=depths[a]){
            ans = min(ans, minlift[j][b]);
            b = binlift[j][b];
        }
        j--;
    }
    if(a!=b){
        for(j = 29;j>=0; j--){
            while(binlift[j][a]!=binlift[j][b]){
                ans = min(ans, min(minlift[j][b], minlift[j][a]));
                a = binlift[j][a];
                b = binlift[j][b];
            }
        }
        ans = min(ans, min(minlift[0][b], minlift[0][a]));
        a = binlift[0][a];
    }
    //cout << "---\n"<< ans << " "<< suma << "\n";
    return 2*ans + (suma - depths[a]*2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    int a,b,c;
    treeadj= vector<vi>(n);
    binlift = vector<vi>(30, vi(n,C));
    minlift =  vector<vi>(30, vi(n,0));
    depths = vi(n, 0);  
    dist = vi(n,0);
    vector<bool> visited(n,false);
    for(int i = 0; i<n; i++){
        cin >> a;
        if(a) {
            qu.push({i,0});
            dist[i] = 0;
            visited[i] = true;
        }

    }
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        treeadj[a-1].push_back(b-1);
        treeadj[b-1].push_back(a-1);
    }
    while(!qu.empty()){
        int c,d; tie(c,d) = qu.front(); qu.pop();
        for(auto a: treeadj[c]){
            if(visited[a]) continue;
            else{
                visited[a] = true;
                dist[a] = d+1;
                qu.push({a,d+1});
            }
        }
    }
    binlift[0][0]=-1;
    root_tree(0,-1);
    iterate_lift();
    for(int i = 0; i<q; i++){
        cin >> a >> b;a--;b--;
        cout <<  query(a,b) << "\n";
    }  
}

