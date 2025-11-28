#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,pair<ll,ll>> qi; //(value,max_val),(max_left_prefix, max_right_prefix)
typedef vector<qi> vq;

ll update_elt(vq & t, int len, int pos, ll val){
    pos += len;
    t[pos].F.F = val;
    t[pos].F.S = max((ll)0,val);
    t[pos].S.F = max((ll)0,val);
    t[pos].S.S = max((ll)0,val);
    for(pos/=2; pos>=1; pos /=2){
        t[pos].F.F = t[2*pos].F.F + t[2*pos + 1].F.F;
        t[pos].S.F = max(t[2*pos].S.F, t[2*pos].F.F + t[2*pos + 1].S.F);
        t[pos].S.S = max(t[2*pos + 1].S.S, t[2*pos + 1].F.F + t[2*pos].S.S);
        t[pos].F.S = max(max(max(t[pos].S.S, t[pos].S.F), max(t[2*pos].F.S, t[2*pos + 1].F.S)), t[2*pos].S.S + t[2*pos + 1].S.F);
    }
    return t[1].F.S;
}

int main(){
    int n,q,x,y;
    cin >> n >> q;
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (1<<(n-1) != tn);
    n = (1<<(n-1));
    vq t(2*n, {{(ll)0,(ll)0},{(ll)0,(ll)0}});
    ll tmp;
    for(int i = 0; i<tn; i++){
        cin >> x;
        tmp = update_elt(t, n, i, x);
    }
   
    for(int i = 0; i<q; i++){
        cin >> x >> y;
        cout << update_elt(t,n,x-1,y) << "\n";
    }
    return 0;
}