#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main(){
    int a, b;
    cin >> a >> b;
    int e = min(a,b);
    a = max(a,b);
    b = e;
    vector<vi> v(a,vi(b,0));
    for(int i = 0; i<b; i++){
        v[0][i] = i;
    }
    for(int i = 0; i<a; i++){
        v[i][0] = i;
    }
    for(int i = 0; i<a; i++){
        for(int j = 1; j<min(i,b); j++){
            v[i][j] = 500*500;
            for(int k = 0; k<((i+1)/2); k++){
                v[i][j] = min(v[i][j], 1 + v[max(i-1-k,j)][min(i-1-k,j)] + v[max(k,j)][min(k,j)]);
            }
            for(int k = 0; k<((j+1)/2); k++){
                v[i][j] = min(v[i][j], 1 + v[max(j-1-k,i)][min(j-1-k,i)] + v[max(k,i)][min(k,i)]);
            }
        }
    }

    cout << v[a-1][b-1] << "\n";
}