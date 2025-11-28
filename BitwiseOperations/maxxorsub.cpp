#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void get_basis(vi & vecs, vi & basis){
    for(auto e: vecs){
        for(int i = 31; i>=0; i--){
            if((e & (1<<i)) && !basis[i]){
                basis[i] = e;
                break;
            }
            else if((e & (1<<i)) && basis[i]){
                e ^= basis[i];
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vi vecs(n);
    for(int i = 0; i<n; i++){
        cin >> vecs[i];
    }
    vi basis(31,0);
    get_basis(vecs, basis);
    int ans = 0;
    for(int i = 31; i>=0; i--){
        if(basis[i]&& ((ans&(1<<i)) == 0)){
            ans ^= basis[i];
        }
    }
    cout << ans << "\n";
}