#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k,n; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    queue<ll> q;
    ll tot = 0;
    ll sum = 0;
    for(int i = 0; i<k; i++){
        q.push(x);
        sum += x;
        x = (a*x + b) % c;
    }
    tot = sum;
    for(int i = k; i<n; i++){
        sum -= q.front(); q.pop();
        q.push(x);
        sum += x;
        x = (a*x + b) % c;
        tot ^= sum;
    }
    cout << tot << "\n";
}