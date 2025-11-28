#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;
    vector<int> arr(n+1, 0);
    vector<int> moves(k);
    for(int i = 0; i<k; i++){
        cin >> moves[i];
    }
    for(int i = 1; i<=n; i++){
        bool pos = false;
        for(int j= 0; j<k; j++){
            if(((i - moves[j])>=0 && (arr[i-moves[j]]==0))){
                arr[i] = 1;
                cout << "W";
                pos = true;
                break;
            }
        }
        if(!pos) cout << "L";
    }
    cout << "\n";
}