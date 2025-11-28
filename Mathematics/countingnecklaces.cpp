#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)

ll expo(ll a, ll b){
    if(b==0) return 1;
    else{
        ll half = expo(a, b/2);
        half = (half* half) % C;
        if(b%2) half = (half*a) % C;
        return half;
    }
}

ll inv(ll a){
    return expo(a, C-2);
}

int main() {
    ll n,k; cin >> n >> k;
    ll invn = inv(n);
    ll ans = expo(k, n);
    for(ll i = 1; i<n; i++){
        ans = (ans + expo(k, gcd(i,n))) % C;
    }
    ans = (ans * invn) %C;
    cout << (ans + C) % C << "\n";
}