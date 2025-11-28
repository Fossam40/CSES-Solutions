#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int,int> pi;
typedef long long ll;
typedef vector<ll> vi;

const int maxsize = (int)(2*1e6 + 2);
vi fwt(maxsize, 0LL);

void update_occ_y(int x, ll d){
    x += (1e6 + 1);
    while(x<maxsize){
        fwt[x]+=d;
        x+= x&-x;
    }
}

ll getnum_pref(int a){
    a += (1e6 + 1);
    ll ans = 0;
    while(a>0){
        ans += fwt[a];
        a-=a&-a;
    }
    return ans;
}

ll getnum(int a, int b){
    return getnum_pref(b) - getnum_pref(a-1);
}

int main(){
    int n; cin >> n;
    vector<pair<pi,bool>> xlines;
    vector<pair<pi,pi>> ylines;
    int x1,y1, x2, y2;
    for(int i = 0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) ylines.push_back({{x1,y1},{x2,y2}});
        else {
            xlines.push_back({{x1,y1},true});
            xlines.push_back({{x2,y2}, false});
        }
    }
    sort(ylines.begin(), ylines.end());
    sort(xlines.begin(), xlines.end());
    ll ans = 0;
    int j = 0;
    for(int i = 0; i<(int)(xlines.size()) ; i++){
        while(j<(int)ylines.size() && ylines[j].F.F < xlines[i].F.F){
            ans += getnum(ylines[j].F.S, ylines[j].S.S);
            j++;
        }
        if(xlines[i].S){
            update_occ_y(xlines[i].F.S, 1LL);
        }
        else{
            update_occ_y(xlines[i].F.S, -1);
        }
    }
    cout << ans << "\n";
}