#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)
#define int long long

ll inv(ll a, ll b = C-2){
    if(b==0) return 1;
    else{
        ll mid = inv(a, b/2);
        mid = (mid*mid)%C;
        if(b%2) mid = (mid*a)%C;
        return mid;
    }
}
// n-1 + m, m
signed main(){
    int n, m; cin >> n >> m;
    vector<ll> facts((ll)(2e6 + 1));
    facts[0] = 1;
    for(int i = 1; i<=(int)(2e6); i++){
        facts[i] = (facts[i-1]*i)%C;
    }
    ll inv1 = inv(facts[m]);
    ll finv = (inv1*inv(facts[n-1]))%C;
    cout << (facts[n-1+m]*finv)%C << "\n";
}