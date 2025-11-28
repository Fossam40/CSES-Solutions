#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    arr[0] = 1;
    for(ll i = 0; i<n; i++){
        for(ll j = 1; j<=6; j++){
            if(i+j <=n){
                arr[i+j]= (arr[i+j] +arr[i]) % (ll)(1e9 + 7);
            }
        }
    }
    cout << arr[n] << "\n";
}