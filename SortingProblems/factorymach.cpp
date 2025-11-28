#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll calc(ll* arr, int len, ll time){
    ll res = 0;
    for(int i = 0; i<len ; i++){
        res += time / (arr[i]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i< n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll time = 0;
    for(ll i = (k*arr[0])/2; i>=1; i /= 2){
        while(calc(arr, n, time + i) < k){time += i;}
    }
    cout << time + 1 << "\n";
}