#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> listadj(n);
    vector<int> outdeg(n,0);
    vector<int> revperm(n);
    vector<int> perm(n);
    int a,b;
    for(int i = 0; i<m; i++){
        cin >> a >> b; a--; b--;
        listadj[b].push_back(a);
        outdeg[a]++;
    }
    for(int i = 0; i<n; i++){
        if(outdeg[i] == 0) pq.push(i);
    }
    int currentelt = n-1;
    while(!pq.empty()){
        int curr = pq.top(); pq.pop();
        revperm[curr] = currentelt--;
        for(auto a: listadj[curr]){
            if((--outdeg[a]) == 0){
                pq.push(a);
            }
        }
    }

    for(int i = 0; i<n; i++) perm[revperm[i]] = i;
    for(int i = 0; i<n; i++) cout << perm[i] + 1 << " ";
    cout << "\n";
}