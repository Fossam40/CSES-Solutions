#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

void get_basis(vi & vecs, vi & basis){
    vi base(31,0);
    for(auto e: vecs){
        for(int i = 31; i>=0; i--){
            if((e & (1<<i)) && !base[i]){
                base[i] = e;
                break;
            }
            else if((e & (1<<i)) && base[i]){
                e ^= base[i];
            }
        }
    }
    for(int i = 0; i<32; i++){
        for(int j = i-1; j>=0; j--){
            if((base[i] & (1<<j)) && base[j]) base[i] ^= base[j];
        }
    }
    for(int i = 0; i<32; i++){
        if(base[i]) basis.push_back(base[i]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,k; cin >> n >> k;
    vi vecs(n);
    for(int i = 0; i<n; i++){
        cin >> vecs[i];
    }
    vi basis;
    get_basis(vecs, basis);
    
    ll nb_repeats = 1 << (ll)min(n - (ll)basis.size(),(ll)20);
    ll ans_shown = 0;
    ll current_val = 0;
    ll current_inds = 0;
    ll current_rep = 0;
    while(ans_shown < k){
        if(current_rep >= nb_repeats){
            current_rep = 0;
            current_val = 0;
            current_inds++;
            ll comp = current_inds;
            ll j = 0;
            while(comp!=0){
                if(comp%2){
                    current_val ^= basis[j];
                }
                j++;
                comp /=2;
            }
        }
        cout << current_val << " ";
        current_rep++;
        ans_shown++;
    }
    cout << "\n";
}