#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll exp(ll a, ll b){
    if(b== 0) return 1;
    ll t = exp(a, b/2);
    t = (t*t) % (ll)(1e9 + 6);
    if(b%2) t = (t*a) % (ll)(1e9 + 6);
    return t;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        cout << exp(a,b) << "\n";
    }
}