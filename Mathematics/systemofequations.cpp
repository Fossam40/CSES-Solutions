#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#pragma once

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		double v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1/A[i][i];
		rep(j,0,n) if (j != i) {
			double fac = (A[j][i] * bv) % C ;
			b[j] = (b[j] - (fac * b[i] %C) + C) % C;
			rep(k,i+1,m) A[j][k] = (((A[j][k] -  (fac*A[i][k] % C)) + C) %C);
		}
		rank++;
	}

	x.assign(m, undefined);
    rep(i,0,rank) {
	    rep(j,rank,m) if (fabs(A[i][j]) > eps) goto fail;
	    x[col[i]] = b[i] / A[i][i];
    fail:; 
    }
}

int main() {
    int n,m; cin >> n >> m;
    vector<vd> A(n, vd(m));
    vd B(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> A[i][j];
        }
        cin >> B[i];
    }
    vd sol (x, n);

}