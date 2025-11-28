#include <bits/stdc++.h>
using namespace std;
#define C (ll)(1e9 + 7)
typedef long long ll;
vector<ll> fact(1000001);

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

ll bin(ll a, ll b){
    if(a<b) return 0LL;
    else if(a==0 || b==0) return 1LL;
    else return (fact[a]*(inv(fact[b]))%C)* inv(fact[a-b]) %C;
}

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    fact[0] = 1;
    for(int i = 1; i<=n; i++) fact[i] = (fact[i-1]*i) % C;
    ll open = 0;
    ll closed = 0;
    bool pos = true;

    for(int i = 0; i<s.size(); i++){
        if(s[i]=='(') open++;
        else closed++;
        if(closed-open > 0) pos = false;
    }
    ll x = (open-closed);
    ll y = n-s.size() + x;
    ll m = y/2;
    ll k = m - x;
    if((y%2!=0)|| !pos || closed>(n/2) || open > (n/2)) cout << "0\n";
    else cout << (bin(k+m, m) -  bin(k+m,m+1) + C) %C<<"\n";
}