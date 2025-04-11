#include <bits/stdc++.h>
using namespace std;

int get_max(int* t, int n, int cap, int k){
    if(t[k]<cap){return 0;}
    else if(t[k]>= cap && k>=n){
        t[k] -= cap;
        int p = k;
        for(p/=2; p>=1; p/=2){
            t[p] = max(t[2*p], t[2*p + 1]);
        }
        return (k-n + 1);
    }
    else{
        if(t[2*k]>= cap) return get_max(t,n,cap, 2*k);
        else return get_max(t,n,cap, 2*k + 1);
    }
}

void update(int* t, int len, int k, int diff){
    k += len;
    t[k] += diff;
    for(k/=2; k>=1; k/=2){
        t[k] = max(t[2*k], t[2*k + 1]);
    }
}

int main(){
    int n, q, x;
    cin >> n >> q;
    int tn = 32 - __builtin_clz(n);
    tn = tn + ((1<<(tn-1)) != n);
    tn = (1<<(tn-1));
    int t[2*tn] = {0};
    for(int i = 0; i<n; i++){
        cin >> x;
        update(t, tn, i, x);
    }
    for(int i = 0; i<q; i++){
        cin >> x;
        cout << get_max(t, tn, x, 1) << " ";
    }
}