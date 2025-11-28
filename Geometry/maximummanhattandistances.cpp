#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    set<ll> xpoints;
    set<ll> ypoints;
    ll maxd = 0;
    ll a,b;
    cin >> a >> b;
    ll c = a;
    a = a+b;
    b = c -b;
    xpoints.insert(a);
    ypoints.insert(b);
    cout << maxd << "\n";
    for(int i = 1; i<n; i++){
        cin >> a >> b;
        c = a;
        a = a+b;
        b = c -b;
        ll maxx = max(abs(*(xpoints.begin()) - a), abs(*(--xpoints.end()) - a));
        ll maxy = max(abs(*(ypoints.begin()) - b), abs(*(--ypoints.end()) - b));
        maxd = max(max(maxx, maxy), maxd);
        xpoints.insert(a);
        ypoints.insert(b);
        cout << maxd << "\n";
    }
}