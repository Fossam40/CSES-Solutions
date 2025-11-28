/* Types of towers: 
 - closed: c(init 2)
 - doubly opened: do (init 1)
 - single both open: sbo (init 1)
 - single open right: sor (init 1)
 - single open left: sol (init 1)

Rec relation:
    - do = do + c
    - sbo = sbo + c + sor + sol
    - sor = sbo + c + sor
    - sol = sbo + c + sol
    - c = 2*c + do + sor + sol + sbo
-> total complexity: 5*n
 */
#include <bits/stdc++.h>
#define C (int)(1e9 + 7)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int main(){
    int n,t;
    vector<vi> v((int)(1e6), vi(5, 0));
    v[0][0] = 2;
    v[0][1] = 1;
    v[0][2] = 1;
    v[0][3] = 1;
    v[0][4] = 1;
    for(int i = 1; i<(int)(1e6); i++){
        v[i][0] = (2* v[i-1][0] + v[i-1][1] + v[i-1][2] + v[i-1][3] + v[i-1][4]) % C;
        v[i][1] = (v[i-1][0] + v[i-1][1]) % C;
        v[i][2] = (v[i-1][0] + v[i-1][2] + v[i-1][3] + v[i-1][4]) % C;
        v[i][3] = (v[i-1][2] + v[i-1][0] + v[i-1][3] + v[i-1][4]) % C;
        v[i][4] = (v[i-1][2] + v[i-1][0] + v[i-1][4] + v[i-1][3]) % C;
    }
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n;
        cout << v[n-1][0] << "\n";
    }
}