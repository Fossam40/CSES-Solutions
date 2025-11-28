#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef vector<vp> vpp;
#define F first
#define S second

pi get_parent(vpp&t, int x1, int y1){
    if(t[x1][y1].F != x1 || t[x1][y1].S != y1){
        pi parent = get_parent(t, t[x1][y1].F, t[x1][y1].S);
        t[x1][y1].F = parent.F;
        t[x1][y1].S = parent.S;
        return parent;
    }
    else return {x1,y1};
}

void unite(vpp& t, int x1, int y1, int x2, int y2){
    pi parent1 = get_parent(t, x1, y1);
    pi parent2 = get_parent(t, x2, y2);
    t[parent1.F][parent1.S].F = parent2.F;
    t[parent1.F][parent1.S].S = parent2.S;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, p;
    p = string(m, '#');
    vpp t(n,vp(m, {-1,-1}));
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] == '.') {
                t[i][j].F = i;
                t[i][j].S = j;
                if(j>0 && s[j-1] == '.') unite(t, i, j, i, j-1);
                if(i>0 && p[j] == '.') unite(t, i, j, i-1, j);
            }
        }
        p = s;
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            count += (t[i][j].F == i && t[i][j].S == j);
        }
    }
    cout << count << "\n";
}
