#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define C (ll)(1e9 +7)

vector<vl> matmul(vector<vl>& a, vector<vl>& b){
    assert(a[0].size() == b.size());
    vector<vl> result(a.size(), vl(b[0].size()));
    for(int i = 0; i<a.size(); i++){
        for(int j = 0; j<b[0].size(); j++){
            for(int k = 0; k<b.size(); k++){
                result[i][j] = (result[i][j] + ((a[i][k]*b[k][j]) % C)) %C;
            }
        }
    }
    return result;
}

vector<vl> expo_mat(vector<vl>& a, ll b){
    if(b==1) return a;
    else{
        vector<vl> half = expo_mat(a, b/2);
        half = matmul(half, half);
        if(b%2) half = matmul(half, a);
        return half;
    }
}

int main() {
    vector<vl> mat = {{1,1},{1,0}};
    vector<vl> init = {{1},{0}};
    ll n; cin >> n;
    if(n==0LL) cout << "0\n";
    else if(n==1LL) cout << "1\n";
    else{
        vector<vl> ans = expo_mat(mat,n-1);
        vector<vl> fans = matmul(ans,init);
        cout << ans[0][0]<< "\n";
    }
}