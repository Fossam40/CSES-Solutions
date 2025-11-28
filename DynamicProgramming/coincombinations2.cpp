#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;
    int coins[n];
    for(int i = 0; i<n; i++){
        cin >> coins[i];
    }
    sort(coins, coins + n);
    int arr[x+1] = {0};
    arr[0] = 1;
    sort(coins, coins+n);
    for(int i = 0; i<n;i++){
        int j = 0;
        while((j+coins[i])<=x && j<x){
            if(arr[j] != 0){
                arr[j+coins[i]]= (arr[j + coins[i]] + arr[j]) % (ll)(1e9 + 7);
            }
            j++;
        }
    }
    cout << arr[x] << "\n";
}