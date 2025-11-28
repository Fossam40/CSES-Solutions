#include <bits/stdc++.h>
using namespace std;

void update(vector<int>& a, int k, int len, int diff){
    k += len;
    a[k] += diff;
    for(k /= 2; k>=1; k /=2){
        a[k] = min(a[k*2], a[(k*2) + 1]);
    }
}

int get_min(vector<int>& arr, int a, int b, int len){
    a += len;
    b += len;
    int m = (int)(1e9 + 1);
    while(a<=b){
        if((a%2)==1){m = min(m,arr[a++]);}
        if((b%2)==0){m = min(m,arr[b--]);}
        a/=2;
        b/=2;
    }
    return m;
}

int main() {
    int n,q,t,x,y;
    cin >> n >> q;
    y = n;
    t = 32 -__builtin_clz(n);
    n = t + ((1<<(t-1)) != n);
    n = (1<<(n-1));
    vector<int> a(n,(int)(1e9 + 1));
    vector<int> f(2*n,(int)(1e9 + 1));
    for(int i = 0; i<y; i++){
        cin >> x;
        update(f,i,n,x-a[i]);
        a[i] = x;
    }
    for(int i = 0; i<q; i++){
        cin >> t >> x >> y;
        if(t==1){
            update(f,x-1, n,y - a[x-1]);
            a[x-1] = y;
        }
        else{
            cout << get_min(f,x-1,y-1,n) << "\n"; 
        }
    }
}