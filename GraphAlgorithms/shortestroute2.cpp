#include <bits/stdc++.h>
using namespace std;
#define INF 3223372036854775807
typedef long long ll;
typedef vector<ll> vl;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vl> mat(n,vl(n,INF));
    int a, b, c;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        c = min((ll)c, mat[a-1][b-1]);
        mat[a-1][b-1] = c;
        mat[b-1][a-1] = c;
    }
    for(int i = 0; i<n; i++){
        mat[i][i] = 0;
    }
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    for(int i = 0; i<q; i++){
        cin >> a >> b;
        if(mat[a-1][b-1] == INF) cout << "-1\n";
        else cout << mat[a-1][b-1] << "\n";
    }
}