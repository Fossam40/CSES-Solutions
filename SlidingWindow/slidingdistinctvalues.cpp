#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    queue<int> q;
    map<int,int> m;
    int ans = 0;
    int x;
    for(int i = 0; i<k; i++){
        cin >> x;
        q.push(x);
        ans += (m[x]==0);
        m[x]++;
    }
    cout << ans << " ";
    for(int i = k; i<n; i++){
        cin >> x;
        q.push(x);
        ans += (m[x]==0);
        m[x]++;
        ans -= ((--m[q.front()])==0); q.pop();
        cout << ans << " ";
    }
}