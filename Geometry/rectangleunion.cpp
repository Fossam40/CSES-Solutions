#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,pair<ll,ll>>> vpl;

const ll N = (1<<21);

vpl tr(2*N, {0,{0,0}});

void push(int c){
    tr[c].S.F += tr[c].F;
    if(c>=N) {
        tr[c].F = 0;
        return;
    }
    tr[2*c].F += tr[c].F;
    tr[2*c+1].F += tr[c].F;
    tr[c].F = 0;
}

ll numzeros(){
    push(1);
    return (N-(tr[1].S.F==0)*tr[1].S.S);
}



void disj(int c){
    push(2*c);
    push(2*c+1);
    if(tr[2*c].S.F == tr[2*c+1].S.F){
        tr[c].S.F = tr[2*c+1].S.F;
        tr[c].S.S = tr[2*c+1].S.S + tr[2*c].S.S;
    }
    else if(tr[2*c].S.F > tr[2*c+1].S.F){
        tr[c].S.F = tr[2*c+1].S.F;
        tr[c].S.S = tr[2*c+1].S.S;
    }
    else{
        tr[c].S.F = tr[2*c].S.F;
        tr[c].S.S = tr[2*c].S.S;
    }
}

void update_range(int c, int d, int a, int b, int r, int l) {
    if(l<a || r>b) return;
    else if(a<=r && l<=b){
        tr[c].F += d;
    }
    else{
        push(c);
        int m = (r+l)/2;
        update_range(2*c, d, a, b, r, m);
        update_range(2*c+1, d, a, b, m+1, l);
        disj(c);
    }
}

void build(int c, int l, int r) {
    tr[c].S.S = (r-l+1);
    if(r==l) return;
    int m = (r+l)/2;
    build(2*c, l, m);
    build(2*c+1, m+1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build(1, 0, N-1);
    int n;
    cin >> n;
    vector<pair<pl,pl>> arr;
    ll a, b, c, d;
    for(int i = 0; i<n; i++){
        cin >> a >> b >> c >> d;
        a+=(1e6); b+=(1e6); c+=(1e6); d+=(1e6);
        arr.push_back({{b, 1},{a,c}});
        arr.push_back({{d, -1},{a,c}});
    }   
    sort(arr.begin(), arr.end());
    int prev = arr[0].F.F;
    ll tot = 0;
    for(int i = 0; i<2*n; i++){
        if(arr[i].F.F != prev){
            tot += (arr[i].F.F-prev)*numzeros();
            prev = arr[i].F.F;
        }
        update_range(1, arr[i].F.S, arr[i].S.F, arr[i].S.S-1, 0, N-1);
    }
    tot += numzeros();
    cout << tot << "\n";
}