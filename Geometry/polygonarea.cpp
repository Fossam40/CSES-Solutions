#include <bits/stdc++.h>
using namespace std;
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

C polygonarea(vector<P> & polygon){
    C ans = 0;
    for(int i = 0; i<polygon.size(); i++){
        P next = polygon[(i+1)%polygon.size()];
        ans += (next.X-polygon[i].X)*(next.Y + polygon[i].Y);
    }
    return abs(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    C x, y;
    vector<P> polygon;
    for(int i = 0; i<n; i++){
        cin >> x >> y;
        polygon.push_back({x,y});
    }
    cout << polygonarea(polygon) << "\n";
}