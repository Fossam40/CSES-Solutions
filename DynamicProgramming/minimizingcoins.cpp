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
    for(int i = 0; i<x;i++){
        if(arr[i] != 0){
            int j = 0;
            while((i+coins[j])<=x && j<n){
                arr[i+coins[j]]=(arr[i+coins[j]]==0)?arr[i]+1:min(arr[i]+1, arr[i + coins[j]]);
                j++;
            }
        }
    }
    cout << arr[x] - 1 << "\n";
}