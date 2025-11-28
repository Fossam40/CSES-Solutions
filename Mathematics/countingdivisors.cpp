#include <bits/stdc++.h>
using namespace std;

int getDivs(int a){
    int res = 0;
    for(int i = 1; (i*i)<=a; i++){
        if(a%i== 0) res += 2 - (i*i==a);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for(int i = 0; i<q; i++){
        int n; cin >> n;
        cout << getDivs(n) << "\n";
    }
}