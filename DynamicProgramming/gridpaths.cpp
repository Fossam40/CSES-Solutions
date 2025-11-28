#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int s;
    ll z = 0;
    cin >> s;
    ll arr[s][s];
    string w;
    for(int i = 0; i< s; i++){
        cin >> w;
        for(int j = 0; j< s; j++){
            arr[i][j] = (w[j] == '.') - 1;
        }
    }
    arr[0][0] +=1;
    for(int i = 0; i< s; i++){
        for(int j = 0; j< s; j++){
            if(arr[i][j] != -1){
                if(j!= 0){ arr[i][j] = (arr[i][j] + max(z, arr[i][j-1])) % (ll)(1e9 + 7);}
                if(i!=0 ){ arr[i][j] = (arr[i][j] + max(z, arr[i-1][j])) %(ll)(1e9 + 7);}
            }
        }
    }
    cout << max(arr[s-1][s-1],z) << "\n";
}