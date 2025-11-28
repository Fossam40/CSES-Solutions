#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> moeb((int)(1e6 + 1), -2);
    vector<int> line((int)(1e6 + 1), 0);
    int x;
    ll buffer = 0;
    for(int i = 0; i<n; i++){
        cin >> x;
        line[x]++;
        if(x == 1) buffer++;
    }
    for(int i = 2; i<=1e6; i++){
        if(moeb[i]==-2){
            for(int j = i; j<1e6 + 1; j+=i){
                if(moeb[j]==-2) moeb[j] = 1;
                else moeb[j] *=-1;
                if(j%(i*i) == 0) moeb[j]= 0;
            }
        }
    }
    __int128_t ans = 0;
    for(int i = 2; i<=1e6; i++){
        __int128_t dk = 0;
        if(moeb[i]!=0){
            for(int j = i; j<= 1e6; j+=i){
                dk += line[j];
            }
        }
        ans += moeb[i]* (dk*(dk-1)/2);
    }
    n-=buffer;
    cout << n*(n-1)/2 - (ll)ans + n*buffer + (buffer*(buffer-1))/2<< "\n";
}