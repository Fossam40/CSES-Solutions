#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;

int main(){
    int n;
    cin >> n;
    int s = 0;
    int c[n];
    for(int i = 0; i<n; i++){
        cin >> c[i];
        s += c[i];
    }
    vector<vb> v(n,vb(s,false));
    v[0][c[0] - 1] = true;
    int a = 1;
    for(int i = 1; i<n; i++){
        a = 1;
        for(int j = 0; j<s; j++){
            if(v[i-1][j] || ((j-c[i])>= 0 && v[i-1][j-c[i]])){
                v[i][j] = true;
                a++;
            }
        }
        a -= v[i][c[i] - 1];
        v[i][c[i] - 1] = true;
    }
    cout << a << "\n";
    for(int i = 0; i<s; i++){
        if(v[n-1][i]){
            cout << i+1 << " ";
        }
    }
} 