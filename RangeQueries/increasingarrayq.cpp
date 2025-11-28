#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef vector<ll> vl;


ll gte_from(vl& t, int len, int target, int a){
    a+= len;
    int prev = 0;
    if(t[a]>=target) return a-len;
    while(a>=1 && (t[a]<target || prev == 1 || (t[2*a + (1-prev)]<target))){
        prev = a%2;
        a /=2;
    }
    if(a<len){a = 2*a + 1;}
    while(a<len){
        a = a*2 + (t[2*a] < target);
    }
    return a - len;
}

void build_gte_from(vl& t, int len, int a, int val){
    a+= len;
    t[a]= val;
    for(a/=2; a>=1 ; a/=2){
        t[a] = max(t[2*a], t[2*a + 1]);
    }
}
 
int main(){
    int n,q, x, y;
    ll tmp;
    scanf("%d %d", &n, &q);
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (1<<(n-1) != tn);
    vector<vl> maxsp(n,vl(tn,0));
    n = (1<<(n-1));
    vl sa(tn + 1, 0);
    vl tf(2*n, (ll)1e9);
    ll s = 0;
    for(int i = 0; i<tn; i++){
        scanf("%lld", &tmp);
        s+= tmp;
        sa[i+1] = s;
        build_gte_from(tf, n, i, tmp);
        maxsp[0][i] = tmp;
    }
    int siz = 2;
    for(int i = 1;i<maxsp.size(); i++){
        for(int j = 0; j<(int)(maxsp[0].size())-siz + 1; j++){
            maxsp[i][j] = max(maxsp[i-1][j], maxsp[i-1][j + siz/2]);
        }
        siz *= 2;
    }
    vl sc(tn + 1, 0);
    for(int i = tn-1; i>=0; i--){
        ll val = sa[i+1]-sa[i];
        int decal = gte_from(tf, n, val, i+1) - i - 1;
        sc[i] = decal*val - (sa[i+decal+1] - sa[i+1]) + sc[i+decal + 1];
    }
    for(int i = 0; i<q; i++){
        scanf("%d %d", &x, &y);
        int k = 32 - (int)__builtin_clz(y-x+1);
        ll lastm =  max(maxsp[k-1][x-1], maxsp[k-1][y-(1<<(k-1))]);
        ll decal = gte_from(tf, n, lastm, y) - y;
        ll c = 0;
        ll m = sa[x]-sa[x-1];
        for(int j = x+1; j<=y; j++){
            m = max(sa[j]-sa[j-1], m);
            c += m - (sa[j]-sa[j-1]);
        }
        printf("%lld\n", (sc[x-1] - (lastm*decal - (sa[y + decal] - sa[y])) - sc[y+decal]));
   }

}