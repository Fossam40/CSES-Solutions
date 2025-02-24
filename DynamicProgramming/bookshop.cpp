#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,x;
    cin >> n >> x;
    int c[n];
    int p[n];
    int d[n][x+1];
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }
    for(int i = 0; i<n; i++){
        cin >> p[i];
    }
    for(int i = 0; i<= x; i++){
        d[0][i] = (i>=c[0])*p[0];
    }
    for(int i = 1; i< n;i++){
        for(int j = 0; j<= x; j++){
            d[i][j] = 0;
            d[i][j] = d[i-1][j];
            if(j-c[i] >= 0){
                d[i][j] = max(d[i][j], p[i] + d[i-1][j - c[i]]);
            }
        }
    }
    cout << d[n-1][x] << "\n";
}