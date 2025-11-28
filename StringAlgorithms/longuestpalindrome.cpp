#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define A 911382323
#define B 972663749
typedef vector<ll> vl;

ll getHash(vl & h, vl & p, int start, int size){
    ll res;
    if(start==0) res = h[size-1];
    else res = (h[start+size-1]- h[start-1]*p[size]) % B;
    return res + (res<0)*B;
}


int oddPal(vl & h, vl & rh, vl & p, int start){
    int n = h.size();
    int ms = min(start+1, n- start);
    int k = 0;
    for(int i = ms; i>=1; i/=2){
        while((k+i)<= ms && (getHash(h, p, start, k+i)== getHash(rh,p,n-1-start, k+i))) k+= i;
    }
    return 2*k-1;
}

int evenPal(vl & h, vl & rh, vl & p, int start){
    int n = h.size();
    int ms = min(start+1, n- 1-start);
    int k = 0;
    for(int i = ms; i>=1; i/=2){
        while((k+i)<= ms && (getHash(h, p, start+1, k+i)== getHash(rh,p,n-1-start, k+i))) k+= i;
    }
    return 2*k;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<ll> h(n);
    vector<ll> rh(n);   
    vector<ll> p(n);
    ll res = 1;
    for(int i = 0; i<n; i++){
        p[i] = res; res = (res*A) % B;
    }
    h[0] = s[0];
    rh[0] = s[n-1];
    for(int i = 1; i<n; i++) h[i] = (A*h[i-1] + s[i]) % B;
    for(int i = 1; i<n; i++) rh[i] = (rh[i-1]*A + s[n-1-i])%B;
    int best = 1;
    int pos = 0;
    bool odd = true;
    for(int i = 1; i<n; i++){
        int cont = oddPal(h, rh, p, i);
        if(cont>best){
            pos = i;
            best = cont;
        }
    }
    for(int i = 0; i<(n-1); i++){
        int cont = evenPal(h, rh, p, i);
        if(cont>best){
            odd = false;
            pos = i;
            best = cont;
        }
    }
    string ans;
    if(odd) ans = s.substr(pos-((best+1)/2)+1, best);
    else ans = s.substr(pos-(best/2)+1, best);
    cout << ans << "\n";
}