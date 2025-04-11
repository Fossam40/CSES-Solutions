#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q,a,b;
    cin >> n >> q;
    int s = 0;
    int t[n+1] = {0};
    for(int i = 1; i<=n; i++){
        cin >> a;
        s ^= a;
        t[i]= s;
    }
    for(int i = 0; i< q; i++){
        cin >> a >> b;
        cout << (t[b] ^ t[a-1]) << "\n";
    }
}