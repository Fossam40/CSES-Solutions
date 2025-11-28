#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl; //left, right
typedef vector<ll> vl;
#define int long long
const int N = 200001;
#define S second
#define F first
int n;
pair<pl,pl> t[2*N];

void build(){
    for(int i = n-1; i>0; i--){
        t[i].F.S = t[i<<1].F.S + t[i<<1|1].F.S;
        t[i].S.S = max(t[i<<1|1].S.S, t[i<<1|1].F.S + t[i<<1].S.S);
        t[i].S.F = max(t[i<<1].S.F, t[i<<1].F.S + t[i<<1|1].S.F);
        t[i].F.F = max(max(t[i<<1].F.F,t[i<<1|1].F.F),max(t[i].S.F, t[i].S.S));
        t[i].F.F = max(t[i].F.F, t[i<<1|1].S.F + t[i<<1].S.S);
    }
}

int query(int l, int r){
    pair<pl,pl> left = {{0,0},{0,0}};
    pair<pl,pl> right = {{0,0},{0,0}};
    for(l+=n, r+=n;l<r;r>>=1,l>>=1){
        if(l&1){
            left.F.F = max(left.F.F, left.S.S + t[l].S.F);
            left.S.S = max(left.S.S + t[l].F.S, t[l].S.S);
            left.S.F = max(t[l].S.F + left.F.S, left.S.F);
            left.F.S += t[l].F.S; 
            left.F.F = max(left.F.F, max(left.S.S, left.S.F));
            left.F.F = max(left.F.F, t[l].F.F);
            l++;
        }
        if(r&1){
            r--;
            right.F.F = max(right.F.F, right.S.F +  t[r].S.S);
            right.S.S = max(t[r].S.S + right.F.S, right.S.S);
            right.S.F = max(right.S.F + t[r].F.S, t[r].S.F);
            right.F.S += t[r].F.S; 
            right.F.F = max(right.F.F, max(right.S.S, right.S.F));
            right.F.F = max(right.F.F, t[r].F.F);
        }
    }
    return max(max(left.F.F, right.F.F), max(left.S.S + right.S.F,0LL));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> n >> q;
    for(int i = 0; i<2*n; i++) t[i] = {{0LL,0LL},{0LL, 0LL}};
    int a, b;
    for(int i = 0; i<n; i++){
        cin >> a;
        int m = max(a,0LL);
        t[n+i] = {{m,a},{m,m}};
    }
    build();
    for(int i = 0; i<q; i++){
        cin >> a >> b;
        cout << query(--a,b) << "\n";
    }
}