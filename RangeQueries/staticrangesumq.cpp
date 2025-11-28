#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, q, x, y;
    cin >> n >> q;
    ll s = 0;
    ll arr[n+1];
    arr[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        s+= arr[i];
        arr[i] = s;
    }
    for(int i = 0; i<q; i++){
        cin >> x >> y;
        cout << arr[y] - arr[x-1] << "\n";
    }
}