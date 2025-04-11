#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define S second
#define F first

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,x,y;
    int c = 1;
    int w = 1;
    cin >> n >> q;
    while(w<=n){
        w *= 2;
        c++;
    }
    vector<vector<int>> m(n,vector<int>(c,0));
    for(int i = 0; i<n; i++){
        cin >> x;
        m[i][0]  = x;
    }
    w = 2;
    c = 1;
    while(w <=n){
        for(int i = 0; i<(n-w+1); i++){
            m[i][c] = min(m[i][c-1], m[i+(w/2)][c-1]);
        }
        w *= 2;
        c++;
    }
    for(int i = 0; i<q; i++){
        cin >> x >> y;
        x = x -1;
        y = y-1;
        w = 1;
        c = 0;
        while(2*w <= (y-x + 1)){ w *= 2;c++;}
        cout << min(m[x][c], m[y-w+1][c]) << "\n";
    }
}