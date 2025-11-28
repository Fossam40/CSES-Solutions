#include <bits/stdc++.h>
using namespace std;
#define A 911382323
#define B 972663749
typedef long long ll;
typedef vector<ll> vl;

ll getHash(vl & pows, vl & h, string & s, int start, int size){
    ll res;
    if(start != 0) res = (h[start-1+size] - (h[start-1]*pows[size])) % B;
    else res = h[start-1+size];
    return res +(res<0)*B;
}

bool compstrings(string &s, int n, int pos1, int pos2, vl & pows, vl & h){ // true if pos2<pos1
    int k = -1;
    for(int i = n/2; i>= 1; i /=2){
        while(((k+i)<=n) && (getHash(pows, h, s, pos1, k+i)==getHash(pows, h, s, pos2, k+i))){k+=i;}
    }
    k+= (k<0);
    return (s[pos1 + k]>s[pos2 + k]);
}

int main() {
    string s; cin >> s;
    int n = s.size();
    s+=s;
    vector<ll> pows(2*n);
    vector<ll> h(2*n);
    ll res = 1;
    for(int i = 0; i<2*n; i++){
        pows[i] = res; res = (res* A) % B;
    }
    h[0] = s[0];
    for(int i = 1; i<2*n; i++){
        h[i] = (h[i-1]*A + s[i]) % B;
    }
    int curr = 0;
    for(int i = 1; i<n; i++){
        if(compstrings(s, n, curr, i, pows, h)) curr = i;
    }
    cout << s.substr(curr, n) << "\n";

}