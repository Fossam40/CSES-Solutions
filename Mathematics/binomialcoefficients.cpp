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

signed main(){
    int n; cin >> n;
    vector<int> facts((ll)(1e6 + 1));
    facts[0] = 1;
    for(int i = 1; i<=(int)(1e6); i++){
        facts[i] = (facts[i-1]*i)%C;
    }
    int a,b;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        ll inv1 = inv(facts[b]);
        ll finv = (inv1*inv(facts[a-b]))%C;
        cout << (facts[a]*finv)%C << "\n";
    }
}