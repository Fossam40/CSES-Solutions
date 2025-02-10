#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pi;
typedef long long ll;
#define F first
#define S second

int main(){
    ll n, x;
    ll s = 0;
    set<pi> c;
    cin >> n;
    ll ans=0;
    c.insert({0,-1});
    for(int i=0;i<n;i++){
        cin >> x;
        s= (((s+x)%n) + n) %n;
        auto it = c.lower_bound({s, (ll)-9223372036854775807});
        if(it != c.end() && (*it).F == s){
            ans-= (*it).S;
            c.insert({s,(*it).S - 1});
        }
        else {
            c.insert({s, -1});
        }
    }
    cout << ans << "\n";
}