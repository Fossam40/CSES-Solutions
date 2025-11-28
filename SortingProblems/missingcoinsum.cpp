#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

int main(){
    int n;
    cin >> n;
    vl t(n);
    for(ll &i: t){
        cin >> i;
    }
    sort(t.begin(), t.end());
    ll c = 0;
    for(auto i: t){
        if(i <= c+1){
            c += i;
        }
        else{
            break;
        }
    }
    cout << c+1 << "\n";

}