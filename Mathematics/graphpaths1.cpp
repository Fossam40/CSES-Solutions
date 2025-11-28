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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,m; cin >> n >> m >>k;
    vector<vl> mat(n, vl(n,0LL));
    ll a,b;
    for(int i = 0; i<m ; i++){
        cin >> a >> b;
        mat[a-1][b-1]++;
    }
    if(k==0LL) cout << "0\n";
    else{
        vector<vl> ansm = expo_mat(mat,k);
        cout << ansm[0][n-1]<< "\n";
    }
}