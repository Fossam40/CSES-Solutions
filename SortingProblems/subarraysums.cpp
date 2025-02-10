#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, x, k;
    int s = 0;
    set<int> c;
    cin >> n >> k;
    int ans=0;
    c.insert(0);
    for(int i=0;i<n;i++){
        cin >> x;
        s+= x;
        auto it = c.find(s-k);
        if(it != c.end()){
            ans++;
        }
        c.insert(s);
    }
    cout << ans << "\n";
}