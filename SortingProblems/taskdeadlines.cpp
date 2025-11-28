#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define F first
#define S second

int main(){
    ll n;
    cin >> n;
    pi a[n];
    for(ll i = 0; i<n; i++){
        cin >> a[i].F >>a[i].S;
    }
    sort(a, a+n);
    ll ans = 0;
    ll time = 0;
    for(ll i = 0; i<n; i++){
        time += a[i].F;
        ans += a[i].S - time;
    }
    cout << ans << "\n";
}