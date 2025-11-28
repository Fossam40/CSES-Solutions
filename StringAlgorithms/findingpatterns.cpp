#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define A 911382323
#define B 972663749
#define F first
#define S second
typedef vector<ll> vl;
 
ll getHash(vl & h, vl & p, int start, int size){
    ll res;
    if(start==0) res = h[size-1];
    else res = (h[start+size-1]- h[start-1]*p[size]) % B;
    return res + (res<0)*B;
}
 
ll simpleHash(string & s){
    ll res = 0;
    for(int i = 0; i<s.size(); i++){
        res = (A*res + s[i]) % B;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    vector<ll> h(n);
    vector<ll> p(n);
    ll res = 1;
    for(int i = 0; i<n; i++){
        p[i] = res; res = (res*A) % B;
    }
    h[0] = s[0];
    for(int i = 1; i<n; i++) h[i] = (A*h[i-1] + s[i]) % B;
    int k; cin >> k;
    vector<string> arr(k);
    set<int> sizes;
    for(int i = 0; i<k; i++){
        cin >> arr[i];
        sizes.insert(arr[i].size());
    }
    set<ll> pos;
    for(auto u: sizes){
        if(u<=n){
            for(int i = 0; i<s.size()-u+1; i++){
                pos.insert(getHash(h,p,i,u));
            }
        }
    }
    for(int i = 0; i<k; i++){
        if(pos.count(simpleHash(arr[i]))) cout << "YES\n";
        else cout << "NO\n";
    }
}