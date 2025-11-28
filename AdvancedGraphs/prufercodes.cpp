#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> code(n-2);
    vector<int> degrees(n,1);
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-2; i++){
        cin >> code[i];
        degrees[--code[i]]++;
    }
    priority_queue<pl> q;
    for(int i = 0; i<n; i++){
        q.push({-degrees[i],-i});
    }
    for(int i = 0; i<n-2; i++){
        pl curr = q.top(); q.pop();
        adj[code[i]].push_back(-curr.S);
        if(curr.F != -1){
            q.push({curr.F + 1, curr.S});
        }
        q.push({-(--degrees[code[i]]), -code[i]});

    }
    int a = - q.top().S; q.pop(); 
    int b = -q.top().S; q.pop();
    adj[a].push_back(b);
    for(int j = 0; j<n;j++){
        for(auto u: adj[j]){
            cout << j+1 << " " << u + 1<< "\n";
        }
    }
}