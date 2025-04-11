#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define F first
#define S second
void update_range(vector<pl>& t, int len, int k, int a, int b, int x, int y, ll diff){
    if( x>b || y<a){}
    else if(a<=x && y <= b){
        t[k].S += diff;
    }
    else{
        int m = (x+y)/2;
        update_range(t,len, 2*k,a,b,x,m,diff);
        update_range(t,len, 2*k + 1,a,b,m+1,y,diff);
        t[k].F = max(t[2*k].F + t[2*k].S, t[2*k + 1].F + t[2*k + 1].S);
    }
}

ll max_prefix(vector<pl>& t, int len, int k, int a, int b, int x, int y, ll prop){
    if(x > b || y<a){
        t[k].S += prop;
        return (ll)(-1e18);
    }
    else if(a<=x && y<=b){
        t[k].S += prop;
        return t[k].F + t[k].S;
    }
    else{
        ll tmp = t[k].S;
        t[k].S = 0;
        int m = (x+y)/2;
        ll ans = max(max_prefix(t, len, 2*k, a, b, x, m, prop + tmp), max_prefix(t, len, 2*k + 1, a, b, m + 1, y, prop + tmp));
        t[k].F = max(t[2*k].F + t[2*k].S, t[2*k + 1].F + t[2*k + 1].S);
        return ans;
    }
}

int main(){
    int n, q;
    ll ty, x,y;
    cin >> n >> q;
    int tmp = ++n;
    n = 32 - __builtin_clz(n);
    n += ((1<<(n-1))!= tmp);
    n = (1<<(n-1));
    vector<ll> arr(tmp,(ll)0);
    ll s = 0;
    vector<pl> t(2*n, {(ll)(-1e18), (ll)0});
    update_range(t,n,1,0,0,0,n-1,(ll)(1e18));
    for(int i = 1; i<tmp; i++){
        cin >> arr[i];
        s += arr[i];
        update_range(t, n, 1, i, i, 0, n-1, s + (ll)(1e18));
    }
    for(int i = 0; i<q; i++){
        cin >> ty >> x >> y;
        if(ty == 1){
            update_range(t, n, 1, x, n-1, 0, n-1, (ll)y-arr[x]);
            arr[x] = y;
        }
        else{
            cout << max(max_prefix(t,n,1,x,y,0,n-1,(ll)0) - max_prefix(t,n,1,x-1,x-1,0,n-1,0),(ll)0)<< "\n";
        }
    }
}