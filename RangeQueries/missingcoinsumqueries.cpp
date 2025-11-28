#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C 1000000001
int n;
vector<vector<int>> tr;


void build(){
    for(int i = n-1; i>0; i--){
        for(int j = 0; j<30; j++){
            tr[i][j] = min(tr[i<<1][j], tr[i<<1|1][j]);
        }
    }
}

int query(int l, int r, int j){
    int curr = C;
    for(l+=n,r+=n; l<r; l>>=1, r>>=1){
        if(r&1) curr = min(curr, tr[--r][j]);
        if(l&1) curr = min(curr, tr[l++][j]);
    }
    return curr;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    tr = vector<vector<int>>(2*(n+1), vector<int>(30,C));
    vector<int> vals(n);
    vector<vector<ll>> segs(30, vector<ll>(n+1, 0));
    for(int i = 0; i<n ; i++){
        cin >> vals[i];
        tr[i+n][63 - __builtin_clzl(vals[i])] = vals[i];
    }
    build();
    for(int i = 0; i<30; i++){
        ll cutover = (1<<(i+1));
        ll carry = 0;
        for(int j = 0; j<n; j++){
            if(vals[j]<cutover){
                carry += vals[j];
            }
            segs[i][j+1] = carry;
        }
    }
    int a,b;
    for(int i = 0; i<q; i++){
        ll ans = 0;
        ll cutover = 0;
        cin >> a >> b;
        while(cutover<30 && ((ans>=((1<<(cutover+1)) - 1)) || ((query(a-1,b,cutover)-1)<=ans))){
            ans = segs[cutover][b] - segs[cutover][a-1];
            cutover++;
        }
        cout << ans+1 << "\n";
    }
}