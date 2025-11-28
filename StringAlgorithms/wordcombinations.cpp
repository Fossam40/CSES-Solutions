#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<ll,vector<ll>> vp;
#define F first
#define S second

int main(){
    vector<vp> trie(1000000, {0,vector<ll>(26,-1)});
    int next = 1;
    int k;
    string s;
    cin >> s;
    cin >> k;
    string l;
    for(int i = 0; i<k;i++){
        cin >> l;
        int curr = 0;
        for(int j = 0; j<l.size(); j++){
            if((trie[curr].S)[l[j]-'a']==(-1)){
                (trie[curr].S)[l[j]-'a']=next;
                next++;
            }
            curr = (trie[curr].S)[l[j]-'a'];
        }
        (trie[curr].F)++;
    }
    int n = s.size();
    vector<ll> nbpos(n+1,0);
    nbpos[n] = 1;
    for(int i = n-1; i>=0; i--){
        int curr = 0;
        for(int j = i; j<n; j++){
            curr = (trie[curr].S)[s[j]-'a'];
            if(curr==-1) break;
            nbpos[i] = (nbpos[i] + ((trie[curr].F * nbpos[j+1]) % (ll)(1e9 + 7))) % (ll)(1e9 + 7);
        }
    }
    cout << nbpos[0] << "\n";
}