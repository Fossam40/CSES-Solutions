#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef long long ll;
typedef pair<ll, pair<ll,ll>> tl;
typedef vector<tl> vt;

void propag_const(vt& t, int k){
    t[k].S.S += t[k].S.F;
    t[k].S.F = 0;
    t[2*k].F = 0;
    t[2*k].S.F = 0;
    t[2*k].S.S = t[k].S.S;
    t[2*k+1].F = 0;
    t[2*k+1].S.F = 0;
    t[2*k+1].S.S = t[k].S.S;
    t[k].S.S = 0;
}

ll get_val(vt &t, int k, int x, int y){
    ll base = (t[k].S.S == 0)?t[k].F:(t[k].S.S*(y-x+1));
    return base + t[k].S.F*(y-x+1);
}

void sum_update(vt& t, int n, int k, int a, int b, int x, int y, ll diff){
    if(k>=2*n) return;
    if(a<=x && y<=b) t[k].S.F += diff;
    else if(y>=a && x<=b){
        int d = (x+y)/2;
        if(t[k].S.S != 0){
            propag_const(t,k);
            t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
        }
        t[k].F += ((max(b,y)-min(a,x) + 1) - abs(b-y) - abs(a-x))*diff; 
        sum_update(t, n, 2*k, a, b, x, d, diff);
        sum_update(t, n, 2*k + 1, a, b, d+1, y, diff);
    }
}

void const_update(vt& t, int n, int k, int a, int b, int x, int y, ll diff){
    if(a<=x && y<=b) {
        t[k].S.S = diff;
        t[k].F = 0;
        t[k].S.F = 0;
    }
    else if(y>=a && x<=b){
        int d = (x+y)/2;
        if(t[k].S.S != 0){
            propag_const(t,k);
            t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
        }
        else{
            t[2*k].S.F += t[k].S.F;
            t[2*k + 1].S.F += t[k].S.F;
            t[k].S.F = 0;
        }
        const_update(t, n, 2*k, a, b, x, d, diff);
        const_update(t, n, 2*k + 1, a, b, d+1, y, diff);
        t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
    }
}

ll get_treev(vt &t, int n, int k, int a, int b, int x, int y){
    if(a<=x && y<= b) return get_val(t, k, x, y);
    else if(y>=a && x<= b){
        int d = (x+y)/2;
        if(t[k].S.S != 0){
            propag_const(t,k);
            t[k].F = get_val(t, 2*k, x, d) + get_val(t, 2*k + 1, d+1, y);
        }
        else if(t[k].S.F != 0){
            t[2*k].S.F += t[k].S.F;
            t[2*k+1].S.F += t[k].S.F;
            t[k].F += (y-x+1)*t[k].S.F;
            t[k].S.F = 0;
        }
        return get_treev(t, n, 2*k, a, b, x, d) + get_treev(t, n, 2*k + 1, a, b, d+1, y);
    }
    else return (ll)0;
}

int main(){
    int n, q;
    cin >> n >> q;
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (1<<(n-1) != tn);
    n = (1<<(n-1));
    vt tr(2*n, {(ll)0,{(ll)0,(ll)0}});
    ll t, a, b, x;
    for(int i = 0; i<tn; i++){
        cin >> t;
        sum_update(tr, n, 1, i, i, 0, n-1, t);
    }
    for(int i = 0; i<q; i++){
        cin >> t >> a >> b;
        if(t==3)
            cout << get_treev(tr, n, 1, a-1, b-1, 0, n-1) << "\n";
        if(t == 1){
            cin >> x;
            sum_update(tr, n, 1, a-1, b-1, 0, n-1, x);
        }
        if(t==2){
            cin >> x;
            const_update(tr, n, 1, a-1, b-1, 0, n-1, x);
        }
    }
}