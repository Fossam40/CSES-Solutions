#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll,pair<ll,ll>> tl;
typedef vector<tl> vp;
#define int long long

void init_update(vp & t, int n, int a, ll val){
    a += n;
    t[a].F = val;
    for(a/=2; a>=1; a /=2) t[a].F = t[2*a].F + t[2*a + 1].F;
}

ll get_val(vp & t, int k, int x, int y){
    if(t[k].S.F!=0){
        return t[k].F + (ll)((y-x+1)*(y-x)/2)*t[k].S.S + (y-x+1)*(t[k].S.F); 
    }
    else return t[k].F;
}

void pol_update(vp & t, int n, int k, int a, int b, int x, int y, ll init){
    if(a<= x && y<=b) {
        t[k].S.F += init;
        t[k].S.S++;
    }
    else if(y>=a && x<=b){
        int d = (x+y)/2;
        if(t[k].S.F != 0){
            t[2*k].S.F += t[k].S.F; 
            t[2*k].S.S+=t[k].S.S;
            t[2*k + 1].S.F += t[k].S.F + (d+1-x)*t[k].S.S;
            t[2*k + 1].S.S+=t[k].S.S;
            t[k].S.F = 0;
            t[k].S.S = 0;
        }
        pol_update(t, n, 2*k, a, b, x, d, init);
        if(a>x) pol_update(t, n, 2*k + 1, a, b, d+1, y, init + max((ll)0, d+1-a));
        else pol_update(t, n, 2*k + 1, a, b, d+1, y, init + d+1-x); 
        t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
    }
}

ll pol_val(vp & t, int n, int k, int a, int b, int x, int y){
    if(a<= x && y<= b) return get_val(t, k, x, y);
    else if(y>= a && x <= b){
        int d = (x+y)/2;
        if(t[k].S.F != 0){
            t[2*k].S.F += t[k].S.F; 
            t[2*k].S.S+=t[k].S.S;
            t[2*k + 1].S.F += t[k].S.F + (d+1-x)*t[k].S.S;
            t[2*k + 1].S.S+=t[k].S.S;
            t[k].S.F = 0;
            t[k].S.S = 0;
        }
        t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
        return pol_val(t, n, 2*k, a, b, x, d) + pol_val(t, n, 2*k+1, a, b, d+1, y);
    }
    return (ll)0;
}

signed main(){
    int n,q;
    cin >> n >> q;
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (1<<(n-1) != tn);
    n = 1<<(n-1);
    vp tr(2*n, {(ll)0,{(ll)0, (ll)0}});
    ll t, a, b;
    for(int i = 0; i<tn; i++){
        cin >> t;
        init_update(tr, n, i, t);
    }
    for(int i = 0; i<q; i++){
        cin >> t >> a >> b;
        if(t == 1){
            pol_update(tr, n, 1, a-1, b-1, 0, n-1, 1);
        }
        else{
            cout << pol_val(tr, n, 1, a-1, b-1, 0, n-1) << "\n";
        }
    }
}
