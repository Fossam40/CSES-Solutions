#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9+7)
//f(n) = (n-1)*f(n-1) + (n-1)*f(n-2)

int main(){
    ll n; cin >> n;
    vector<ll> arr(1e6 + 1);
    arr[1] = 0;
    arr[2] = 1;
    for(int i = 3; i<=n; i++){
        arr[i] = ((i-1)*((arr[i-1] + arr[i-2])%C))%C;
    }
    cout << arr[n] << "\n";
}