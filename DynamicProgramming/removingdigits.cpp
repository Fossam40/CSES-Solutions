#include <bits/stdc++.h>
using namespace std;

int maxdig(int a){
    int m = 0;
    while(a != 0){
        m = max(m, a % 10);
        a/=10;
    }
    return m;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n != 0){
        n -= maxdig(n);
        ans++;
    }
    cout << ans << "\n";
}