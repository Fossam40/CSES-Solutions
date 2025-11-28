#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;

#define C (int)(1<<18)
#define F first
#define S second

vector<pi> tr(2*C, {0,(int)(-1e18)});

int f(pi params, int x){
    return (params.F*x) + params.S;
}

int get_max(int n, int x, int a, int b){
    int m = (a+b)/2;
    if(a-b==0) return f(tr[n], x);
    else if(x<=m){
        return max(f(tr[n], x), get_max(2*n, x, a, m));
    }
    else return max(f(tr[n], x), get_max(2*n + 1, x, m+1, b));
}

void add_function(int n, pi nw, int l, int r, int a, int b){
    if(r<a || l>b) return;
    int m = (a+b)/2;
    if(l<=a && b<=r){
        bool midint = f(nw, m) > f(tr[n], m);
        bool lint = f(nw, a) > f(tr[n],a);
        if(midint) swap(nw, tr[n]);
        if(b-a==0) return;
        if(lint!=midint){
            add_function(2*n, nw, l, r, a, m);
        }
        else add_function(2*n + 1, nw, l, r, m+1, b);
    }
    else{
        if(b-a==0) return;
        add_function(2*n, nw, l, r, a, m);
        add_function(2*n+1, nw, l, r, m+1, b);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int t, a, b,l,r;
    for(int i = 0; i<n; i++){
        cin >> t;
        if(t== 1){
            cin >> a >> b >> l >> r;
            add_function(1, {a,b}, l, r, 0, C-1);
        }
        else{
            cin >> a;
            int ans = get_max(1, a, 0, C-1);
            if(ans == (int)(-1e18)) cout << "NO\n";
            else cout << ans << "\n";
        }
    }
}