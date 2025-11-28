#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define F first
#define S second

int main(){
    ll k,n; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    deque<pl> q;
    ll tot = 0;
    q.push_back({x,0}); x = (a*x + b) % c;
    for(int i = 1; i<k; i++){
        while(!q.empty() && q.back().F >= x) q.pop_back();
        q.push_back({x,i});
        x = (a*x + b) % c;
    }
    tot = q.front().F;
    for(int i = k; i<n; i++){
        if(q.front().S == (i-k)) q.pop_front();
        while(!q.empty() && q.back().F >= x) q.pop_back();
        q.push_back({x,i});
        tot ^= q.front().F;
        x = (a*x + b) % c;
    }
    cout << tot << "\n";
}