#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (int)(1e9 + 7)

int main() {
    ll n,x; cin >> n;
    map<ll, ll> counts;
    for(int i = 0; i<n; i++){
        cin >> x; counts[x]++;
    }
    ll ans = 1;
    for(auto elt: counts){
        ans = (ans * (elt.second+1)) % C;
    }
    ans -= 1;
    ans += C*(ans<0);
    cout << ans << endl;
}