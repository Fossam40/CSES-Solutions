#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_sum(ll* t, int len, int a, int b){
    a += len;
    b += len;
    ll s = 0;
    while(a <= b){
        if(a%2 == 1){s += t[a++];}
        if(b%2 == 0){s += t[b--];}
        b/=2;
        a/=2;
    }
    return s;
}

void add_to(ll* t, int len, int k, ll diff){
    k += len;
    while(k >= 1){
        t[k] += diff;
        k /= 2;
    }
}

int main(){
    int n, q, t, x, y;
    ll u;
    cin >> n >> q;
    int p = 0;
    y = n;
    t = 32 - __builtin_clz(n);
    n = t + ((1<<t) != n);
    n = (1<<(n-1));
    ll tr[2*n] = {0};
    for(int i = 0; i<y; i++){
        cin >> x;
        add_to(tr, n, i, x-p);
        p = x;
    }
    for(int i = 0; i<q; i++){
        cin >> t;
        if(t==1){
            cin >> x >> y >> u;
            add_to(tr, n, x-1, u);
            add_to(tr, n, y, -u);
        }
        else{
            cin >> x;
            cout << get_sum(tr, n, 0, x-1) << "\n";
        }
    }
}