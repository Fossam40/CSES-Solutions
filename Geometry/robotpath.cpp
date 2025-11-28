#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int,int> pi;
typedef long long ll;
typedef vector<ll> vi;

int main(){
    int n;
    vector<pair<pi,pi>> lines;
    vector<char> directions;
    pi curr = {0,0};
    char c; int dist;
    for(int i = 0; i<n; i++){
        cin >> c >> dist;
        directions.push_back(c);
        if(c=='U'){
            lines.push_back({{curr.F, curr.S}, {curr.F, curr.S + dist}});
            curr.S += dist;
        }
        else if(c=='D'){
            lines.push_back({{curr.F, curr.S - dist}, {curr.F, curr.S}});
            curr.S -= dist;
        }
        else if(c=='R'){
            lines.push_back({{curr.F, curr.S}, {curr.F + dist, curr.S}});
            curr.F += dist;
        }
        else if(c=='L'){
            lines.push_back({{curr.F - dist, curr.S}, {curr.F, curr.S}});
            curr.F -= dist;
        }
    }
    int min_line = get_min_line(lines);
    if(min_line == -1){
        cout << curr.F << " " << curr.S << "\n";
    }
    else {
        pi closest_point = closest_cross(lines[min_line]);
        cout << closest_point.F << " " << closest_point.S << "\n";
    }

}