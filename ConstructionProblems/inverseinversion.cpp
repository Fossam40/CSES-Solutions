#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k; cin >> n >> k;
    vector<ll> sol(n, -1);
    int i = 0;
    while(i<(n-1) && k-(n-1-i)>=0){
        k -= (n-1-i);
        sol[n-1-i] = i+1;
        i++;
    }
    sol[k] = i+1;
    i++;
    for(int j = 0; j<n; j++){
        if(sol[j]==-1){
            sol[j] = i+1;
            i++;
        }
    }
    for(auto a: sol) cout << a << " ";
}