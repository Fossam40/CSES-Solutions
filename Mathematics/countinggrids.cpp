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
    ll n; cin >> n;
    ll inv4 = inv(4LL);
    ll ans = expo(2LL, n*n);
    ll quarter= expo(2LL, (n/2)*(n/2));
    ll half = expo(2LL, n*(n/2));
    if(n%2) {
        quarter = (quarter * expo(2LL, ((n+1)/2))) % C;
        half = (half * expo(2LL, (n+1)/2) )%C;
    }
    quarter = (2 * quarter) % C;
    ans = (ans + quarter) % C;
    ans = (ans + half) %C;
    ans = (ans * inv4) %C;
    cout << (ans + C) % C << "\n";
}