#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll,pair<ll,ll>> pl;
int main(){
    int n;
    cin >> n;
    map<int,ll> m;
    m[0] = 0;
    pl arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i].S.F >> arr[i].F >> arr[i].S.S;
    }
    sort(arr, arr + n);
    for(int i = 0; i<n; i++){
        auto ps = --(m.lower_bound(arr[i].S.F));
        auto p = --(m.upper_bound(arr[i].F));
        m[arr[i].F] = max((*p).S, (*ps).second + arr[i].S.S);
    }
    cout << m[arr[n-1].F] << "\n";
}