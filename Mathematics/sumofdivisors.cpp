#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)
ll sigma(ll n){
    ll ans = n%C;
    ans += (((ans*(ans+1))/2) - 1) % C;
    ans = ans % C;
    ll i;
    for(i = 2; (i*i)<=n; i++){
        ll modrest =  (n/i) %C;
        ans = (ans + i*(modrest-i+1)) % C;
        if(modrest>=(i+1)) ans = (ans + ((i+1 + modrest)*((abs(modrest-i-1)+1)%C))/2) % C;
    }
    return (ans)%C;
}

int main(){
    ll n;
    cin >> n;
    cout << sigma(n) << endl;
}