#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    string n,m;
    cin >> n >> m;
    vector<vi> v(n.size() + 1, vi(m.size() + 1, 0));
    for(int i = 0; i<=m.size(); i++){
        v[0][i] = i;
    }
    for(int i = 0; i<=n.size(); i++){
        v[i][0] = i;
    }
    for(int i = 1; i<=n.size(); i++){
        for(int j = 1; j<=m.size(); j++){
            v[i][j] = min(v[i-1][j-1] + (n[i-1]!=m[j-1]), min(v[i][j-1] + 1, v[i-1][j] + 1));
        }
    }
    cout << v[n.size()][m.size()] << "\n";
}