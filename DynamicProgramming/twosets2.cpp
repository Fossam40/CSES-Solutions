#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main(){
    int n;
    cin >> n;
    vector<vl> arr(n,vl((n*(n+1))/2 + 1, 0));
    int s = 1;
    arr[0][1] = 1;
    for(int i = 1; i<n; i++){
        s += i+1;
        for(int j = 0; j<=s; j++){
            arr[i][j] += arr[i-1][j+i+1];
            if(j!= 0 && (i+1)>j){
                arr[i][j] += arr[i-1][i+1-j];
            }
            if(j>=(i+1)){
                arr[i][j] += arr[i-1][j-i-1];
            }
            if(j==(i+1)){
                arr[i][j] += arr[i-1][0];
            }
            arr[i][j] = arr[i][j] % (ll)(1e9 + 7);
        }
    }
    cout << arr[n-1][0] << "\n";
}