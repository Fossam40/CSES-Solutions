#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> & ino, vector<int> & revino, queue<int> & pre, int a, int b) {
    if(a>b) return;
    int curr = pre.front(); pre.pop();
    if(a==b) cout << curr +1 << " ";
    else{
        solve(ino, revino, pre, a, revino[curr]-1);
        solve(ino, revino, pre, revino[curr] + 1, b);
        cout << curr +1 << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    queue<int> pre;
    vector<int> ino(n);
    vector<int> revino(n);
    int x;
    for(int i = 0; i<n; i++){
        cin >> x;
        pre.push(--x);
    }
    for(int i = 0; i<n; i++) {
        cin >> ino[i]; 
        revino[--ino[i]] = i;
    }
    solve(ino, revino, pre, 0, n-1);
    cout << "\n";
}