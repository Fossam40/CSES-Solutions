#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll sum = 0;
    ll m = k;
    ll z = 0;
    for(int i = 0; i< n ; i++){
        sum += k;
        m = max(m, sum);
        sum = max(sum, z);
        if(i != n-1){cin >> k;}
    }
    cout << m << "\n";
}