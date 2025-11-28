#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define F first
#define S second
typedef vector<pl> vl;

//b_s(fp,a,b) = max(init+bss(a+1,b), end + bss(a,b-1))
int main(){
    int n;
    cin >> n;
    vector<vl> v(n,vl(n));
    int board[n];
    for(int i = 0; i<n; i++){
        cin >> board[i];
        v[i][i].F = board[i];
        v[i][i].S = board[i];
    }
    for(int i = 1; i<n; i++){
        for(int j = i-1; j >= 0; j--){
            v[i][j].F = max(board[j] + (v[i][j+1].S - v[i][j+1].F), board[i] + (v[i-1][j].S - v[i-1][j].F));
            v[i][j].S = v[i][j+1].S + board[j];
        }
    }
    cout << v[n-1][0].F << "\n";
}