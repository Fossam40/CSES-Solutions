#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> arr(k);
    for(int i = 0; i<k; i++){
        cin >> arr[i];
    }
    __int128_t ans = 0;
    for(int i = 1; i < (1<<k); i++){
        __int128_t sign;
        if(__builtin_popcount(i)%2==0) sign = -1;
        else sign = 1;
        __int128_t curr = 1;
        for(int j = 0; j<21; j++){
            if(i&(1<<j)) {
                if(curr*arr[j]>n){
                    sign = 0; break;
                }
                curr *= arr[j];
            }
        }
        ans += sign*(n/curr);
    }
    cout << (ll)ans << "\n";
}