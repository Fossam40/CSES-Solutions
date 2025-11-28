#include <bits/stdc++.h>
using namespace std;
#define X real()
#define Y imag()
#define F first
#define S second

typedef pair<long long, long long> pl;
typedef long long ll;

ll distp(pl a, pl b){
    return (a.F - b.F )*(a.F - b.F) + (a.S - b.S )*(a.S - b.S);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pl> points(n);
    for(int i = 0; i<n; i++){
        cin >> points[i].F >> points[i].S;
    }
    sort(points.begin(), points.end());
    ll d = distp(points[0], points[1]);
    set<pl> yrange;
    int filter = 0;
    for(int i = 0; i<n; i++){
        ll dp = sqrt(d);
        while(dp*dp>d)dp--;
        while(dp*dp <= d) dp++;
        while(filter < n && points[filter].F <= (points[i].F - dp)){
            yrange.erase({(points[filter]).S, (points[filter]).F});
            filter++;
        }
        auto yiter = yrange.upper_bound({points[i].S - dp, -(1e9 + 1)});
        while(yiter != yrange.end() && (*yiter).F < (points[i].S + dp)){
            d = min(d, distp(*yiter, {points[i].S, points[i].F}));
            yiter++;
        }
        yrange.insert({points[i].S, points[i].F});
    }
    cout << d << "\n";
}