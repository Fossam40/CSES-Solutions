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
    vector<ll> facts((ll)(1e6 + 1));
    facts[0] = 1;
    for(int i = 1; i<=(int)(1e6); i++){
        facts[i] = (facts[i-1]*i)%C;
    }
    string s; cin >> s;
    ll ans = facts[s.size()];
    sort(s.begin(), s.end());
    char prev = s[0];
    int count = 0;
    int i = 0;
    while(i<s.size()){
        if(prev == s[i]) count++;
        else{
            ans = (ans*inv(facts[count]))%C;
            count = 1;
            prev = s[i];
        }
        i++;
    }
    ans = (ans*inv(facts[count]))%C;
    cout << ans << "\n";
}