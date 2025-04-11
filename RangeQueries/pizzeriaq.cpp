#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef pair<pair<int,int>,pair<int,int>> qi;
typedef vector<qi> vq;
typedef vector<int> vi;

void update_range(vq & t,int len, int pos, int val){
    pos += len;
    t[pos].F.F = val;
    t[pos].F.S = val;
    t[pos].S.F = pos - len;
    t[pos].S.S = pos - len;
    int dist = 1;
    for(pos/=2; pos>=1; pos/=2){
        if(t[2*pos].F.F >= dist + t[2*pos + 1].F.F){
            t[pos].F.F = dist + t[2*pos + 1].F.F;
            t[pos].S.F = t[2*pos + 1].S.F;
        }
        else{
            t[pos].F.F = t[2*pos].F.F;
            t[pos].S.F = t[2*pos].S.F;
        }
        if(t[2*pos].F.S + dist <= t[2*pos + 1].F.S){
            t[pos].F.S = dist + t[2*pos].F.S;
            t[pos].S.S = t[2*pos].S.S;
        }
        else{
            t[pos].F.S = t[2*pos + 1].F.S;
            t[pos].S.S = t[2*pos + 1].S.S;
        }
        dist *= 2;
    }
}

int get_closest(vq & t, vi & pr, int len, int pos){
    int ipos = pos;
    int cm = pr[pos];
    pos += len;
    for(pos; pos>1; pos /=2){
        int brother = pos + 2*(pos%2 == 0) - 1;
        //cout << "MY brother is " << brother << "\n";
        if(brother%2 != 1){
            cm = min(cm, pr[t[brother].S.S] + abs(t[brother].S.S - ipos));
        }
        else{
            //cout << "Dist: " << t[brother].S.F <<"\n";
            cm = min(cm, pr[t[brother].S.F] + abs(t[brother].S.F - ipos));
        }
    }
    return cm;
}

int main() {
    int n, q, ty, x, y;
    cin >> n >> q;
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (1<<(n-1) != tn);
    n = (1<<(n-1));
    vq t(2*n, {{(int)1e9,int(1e9)},{0,0}});
    vi pr(n,(int)1e9);
    for(int i = 0; i<tn;i++){
        cin >> ty;
        pr[i] = ty;
        update_range(t,n,i,ty);
    }
    cout << "\n";
    for(int i = 0; i<q; i++){
        cin >> ty;
        if(ty==1) {
            cin >> x >> y;
            update_range(t,n, x-1, y);
            pr[x-1] = y;
        }
        else{
            cin >> x;
            cout << get_closest(t, pr, n, x-1) << "\n";
        }
    }

}

