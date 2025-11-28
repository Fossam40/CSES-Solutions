#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)
#define I2 (ll)500000004
ll expmod(ll a, ll b, ll c=C){
    if(b==0) return 1;
    else{
        ll halved = expmod(a, b/2,c);
        ll ans = (halved*halved) % c;
        if(b%2) ans = (ans*a) % c;
        return ans;
    }
}

int main() {
    ll n; cin >> n;
    ll numdivs = 1;
    ll sumdivs = 1;
    ll proddivs = 1;
    ll tot = 1;
    ll p, alp;
    ll numdivsp = 1;
    for(int i = 0; i<n; i++){
        cin >> p >> alp;
        proddivs = (expmod(proddivs, alp+1)*expmod(expmod(p, ((alp)*(alp+1)/2)%(C-1)), numdivsp))%C;
        tot = (tot * expmod(p, alp)) %C;
        numdivs = (numdivs*(alp+1))%C;
        numdivsp = (numdivsp*(alp+1))%(C-1);
        ll topsd = ((expmod(p,(alp+1)))%C)-1;
        topsd += C*(topsd<0);
        ll inv = expmod(p-1, C-2);
        sumdivs = (sumdivs * ((topsd*inv)%C))%C;
    }
    cout << numdivs << " "<< sumdivs << " "<< proddivs << endl;
}