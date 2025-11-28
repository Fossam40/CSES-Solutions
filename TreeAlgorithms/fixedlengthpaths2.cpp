#include <bits/stdc++.h>
using namespace std;
#define int long long
long long ans = 0;
typedef vector<int> vi;
vector<vi> adj;
int k;

void merge(deque<int> & a, deque<int> & b){
    if(a.size()<b.size()) swap(a,b);
    int bs = b.size();
    bool first = true;
    for(int i = 0; i<bs; i++){
        if((k-i)>=0 && (k-i)<a.size()){
            if(first){
                ans += b[i]*a[k-i];
                first = false;
            }
            else ans += b[i]*(a[k-i]-a[k-i+1]);
        }
    }
    for(int i = 0; i<bs; i++){
        a[i] += b[i];
    }
}

deque<int> solve(int curr, int par){
    deque<int> parentm({1});
    for(auto e: adj[curr]){
        if(e!= par){
            auto child = solve(e, curr);
            child.push_front(child[0]);
            merge(parentm, child);
        }
    }
    return parentm;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; int k2;
    cin >> n >> k2 >> k; k++;
    int a,b;
    adj = vector<vi>(n);
    for(int i = 0; i<n-1; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    solve(0,-1);
    ans = ans * (-1);
    k = k2;
    solve(0,-1);
    cout << ans << "\n";
}