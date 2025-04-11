#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(int k, ll* arr){
    ll s = 0;
    while(k>=1){
        s += arr[k];
        k -= k&(-k);
    }
    return s;
}

void update(int k, int diff, int len, ll* arr){ //diff = new-prev
    while(k<=len){
        arr[k]+= diff;
        k += k&(-k);
    }
}

int main(){
    int n, q, x, y, z;
    cin >> n >> q;
    ll a[n+1] = {0};
    int h[n+1] = {0};
    for(int i = 1; i<=n; i++){
        cin >> x;
        h[i] = x;
        update(i,x,n,a);
    }
    for(int i = 0; i<q; i++){
        cin >> x >> y >> z;
        if(x==1){
            update(y, z - h[y], n, a);
            h[y] = z;
        }
        else{
            cout << sum(z,a) - sum(y-1,a) << "\n";
        }
    }
}