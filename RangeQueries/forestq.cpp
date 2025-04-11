#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n, q, y1, x1, y2, x2; // y = line
    cin >> n >> q;
    vector<vi> arr(n,vi(n,0));
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int j = 0; j<n; j++){
            arr[i][j] = (s[j]=='*');
        }
    }
    int s = 0;
    for(int j = 0; j<n; j++){
        s += arr[0][j];
        arr[0][j] = s;
    }
    s = 0;
    for(int j = 0; j<n; j++){
        s += arr[j][0];
        arr[j][0] = s;
    }
    for(int i = 1; i< n; i++){
        for(int j = 1; j<n; j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for(int i = 0; i<q; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        int q = arr[y2-1][x2-1];
        if(x1 > 1){
            q -= arr[y2-1][x1 - 2];
        }
        if(y1 > 1){
            q -= arr[y1 - 2][x2 - 1];
        }
        if (x1 > 1 && y1 > 1){
            q += arr[y1-2][x1-2];
        }
        cout << q << "\n";
    }
}