#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    map<int,int> m;
    m[0] = 0;
    int bs = 0;
    for(int i = 0; i<n; i++){
        cin >> x;
        auto e = --(m.lower_bound(x));
        if(m.count(x)){m[x] = max(m[x], (*e).second + 1);}
        else{m[x] = (*e).second + 1;}
        auto u = (m.upper_bound(x));
        if(u != m.end() && (*u).second <= m[x]){m.erase(u);}
        bs = max(bs, m[x]);
    }
    cout << bs << "\n";
}