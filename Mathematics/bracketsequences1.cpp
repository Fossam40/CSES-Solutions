#include <bits/stdc++.h>
using namespace std;
#define C (ll)(1e9 + 7)
typedef long long ll;

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
    vector<ll> fact(n+1);
    fact[0] = 1;
    for(int i = 1; i<=n; i++) fact[i] = (fact[i-1]*i) % C;
    if(n%2) cout << "0\n";
    else cout << ((((fact[n]*(inv(fact[n/2]))%C)* inv(fact[n/2]) %C) -  ((fact[n]*(inv(fact[(n/2) -1]))%C)* inv(fact[(n/2) +1]) %C)) + C) %C<<"\n";
}