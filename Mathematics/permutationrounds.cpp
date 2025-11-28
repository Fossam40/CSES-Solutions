#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)
#define int long long
ll prime[200001] = {0};

void decomp(ll a){
    for(int i = 2; i*i <= a; i++){
        int j = 0;
        while((a%i) == 0){
            a /= i;
            j++;
        }
        prime[i]= max(prime[i],j);
    }
    if(a != 1) prime[a] = max(prime[a],1LL);
}

ll expo(ll a, ll b){
    if(b==0) return 1;
    else{
        ll half = expo(a, b/2);
        half = (half* half) % C;
        if(b%2) half = (half*a) % C;
        return half;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n);
    vector<bool> seen(n, false);
    for(int i = 0; i<n; i++) cin >> arr[i];
    vector<ll> vals;
    set<ll> seenvals;
    for(int i = 0; i<n; i++){
        if(!seen[i]){
            int j = i;
            int len = 0;
            while(!seen[j]){
                seen[j] = true;
                len++;
                j = arr[j]-1;
            }
            if(!seenvals.count(len)){
                vals.push_back(len);
                seenvals.insert(len);
            }
        }
    }
    for(auto a: vals) decomp(a);
    ll ans = 1;
    for(int i = 1; i<200001; i++){
        ans = (ans * expo(i, prime[i])) %C;
    }
    cout << ans << "\n";
}