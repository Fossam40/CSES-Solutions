#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getAns(ll a){
    if(a<=1) return a;
    ll pow = (64-__builtin_clzll(a));
    ll ans = (pow-1)*(1LL<<(pow-2));
    return ans + getAns(a%(1LL<<(pow-1))) + ((a%(1LL<<(pow-1)))+1);
}

int main(){
    ll n;
    cin >> n;
    cout << getAns(n) << endl;
}