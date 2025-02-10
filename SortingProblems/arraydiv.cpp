#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define F first
#define S second

bool f(int* arr, int n, int k, ll tr){
    int o = 0;
    ll s = 0;
    for(int i = 0; i< n; i++){
        if(o > k || arr[i] > tr){
            return false;
        }
        if(s==0){s+=arr[i];}
        else{
            if(s+arr[i] > tr){
                s=arr[i];
                o++;
            }
            else{s+= arr[i];}
        }
    }
    return (o<k);
}
int main() {
    int n, k;
    cin >> n >> k;
    ll s = 0;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
        s+= arr[i];
    }
    ll tr = 0;
    for(ll i = s/2; i>= 1; i /= 2){
        while(! (f(arr, n, k, tr + i))){tr += i;}
    }
    cout << tr + 1 << "\n";
}