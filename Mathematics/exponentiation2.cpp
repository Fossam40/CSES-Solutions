#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll exp(ll a, ll b){
    if(b== 0) return 1;
    ll t = exp(a, b/2);
    t = (t*t) % (ll)(1e9 + 7);
    if(b%2) t = (t*a) % (ll)(1e9 + 7);
    return t;
}

ll raexp(ll a, ll b){
    if(b== 0) return 1;
    ll t = raexp(a, b/2);
    t = (t*t) % (ll)(1e9 + 6);
    if(b%2) t = (t*a) % (ll)(1e9 + 6);
    return t;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        cout << exp(a,raexp(b,c)) << "\n";
    }
}