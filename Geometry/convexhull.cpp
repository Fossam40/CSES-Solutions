#include <bits/stdc++.h>
using namespace std;

typedef long long C;
typedef complex<C> P;
typedef pair<C,C> pl;
#define X real()
#define Y imag()
#define F first
#define S second

C cross(pl p1, pl p2, pl p3){
    pl line1 = {p2.F - p1.F, p2.S - p1.S};
    pl line2 = {p3.F - p2.F, p3.S - p2.S};
    return line1.F*line2.S - line1.S*line2.F;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    vector<pl> points(n);
    set<pl> inpoints;
    for(int i = 0; i<n; i++){
        cin >> points[i].F >> points[i].S;
    }
    sort(points.begin(), points.end());

    vector<pl> upper;
    vector<pl> lower;
    upper.push_back(points[0]);
    upper.push_back(points[1]);
    for(int i = 2; i<n; i++){
        while(upper.size() > 1 && (cross(upper[upper.size()-2], upper[upper.size()-1], points[i]) > 0LL)){
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }
    lower.push_back(points[0]);
    lower.push_back(points[1]);
    for(int i = 2; i<n; i++){
        while(lower.size() > 1 && (cross(lower[lower.size()-2], lower[lower.size()-1], points[i]) < 0LL)){
            lower.pop_back();
        }
        lower.push_back(points[i]);
    }
    for(auto a: lower) inpoints.insert(a);
    for(auto a: upper) inpoints.insert(a);
    cout << inpoints.size() << "\n";
    for(auto a: inpoints) cout << a.F << " "<< a.S << "\n";
}