#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll s = 0;
    ll m = 0;
    ll n;
    ll x;
    cin >> n;
    for(ll i =0; i< n; i++){
        cin >> x;
        m = max(m,x);
        s += x; 
    }
    if((s-m)<m){
        cout << 2 * m << "\n";
    }
    else{
        cout << s << "\n";
    }
}