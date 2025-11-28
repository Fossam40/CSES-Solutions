#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

#define C (int)(1<<18)
#define F first
#define S second

vector<pi> tr(2*C, {0,-1});

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
    int n,m; cin >> n >> m;
    int x1, x2, y1, y2;
    for(int i = 0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int slope = (y2-y1)/(x2-x1);
        int offset = y1 - slope*x1;
        add_function(1, {slope, offset}, x1, x2, 0, C-1);
    }
    for(int i = 0; i<=m; i++){
        cout << get_max(1, i, 0, C-1) << " ";
    }
    cout << "\n";
}