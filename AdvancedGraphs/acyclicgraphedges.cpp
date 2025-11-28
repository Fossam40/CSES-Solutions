#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m; cin >> n >> m;
    ll a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        cout << min(a,b) << " " << max(a,b) << "\n";
    }
}