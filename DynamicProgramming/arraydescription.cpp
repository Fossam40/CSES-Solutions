#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int main(){
    int n, m;
    int x;
    cin >> n >> m;
    vector<vi> v(n, vi(m,0));
    cin >> x;
    if(x== 0){
        for(int i = 0; i<m;i++){
            v[0][i] = 1;
        }
    }
    else{v[0][x-1] = 1;}
    for(int i = 1; i<n; i++){
        cin >> x;
        if(x== 0){
            for(int j = 0; j<m;j++){
                for(int k = max(0,j-1); k<=min(m-1,j+1); k++){
                    v[i][j] = (v[i][j] + v[i-1][k]) % (int)(1e9 + 7);
                }
            }
        }
        else{
            int j = x-1;
            for(int k = max(0,j-1); k<=min(m-1,j+1); k++){
                    v[i][j] = (v[i][j] + v[i-1][k]) % (int)(1e9 + 7);
            }
        }
    }
    ll s = 0;
    for(int i = 0; i<m; i++){
        s = (s + v[n-1][i]) % (int)(1e9 + 7);
    }
    cout << s << "\n";
}