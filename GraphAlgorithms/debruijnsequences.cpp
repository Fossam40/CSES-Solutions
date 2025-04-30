#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    if(n!=1){
        int size = (1<<(n-1));
        vector<vi> adj(size);
        vi sizes(size,2);
        for(int i = 0; i<size; i++){
            adj[i].push_back((2*i)%(size));
            adj[i].push_back((2*i + 1)%(size));
        }
        stack<int>calls;
        stack<int> path;
        calls.push(0);
        while(!calls.empty()){
            int curr = calls.top();
            if(sizes[curr]==0){
                path.push(curr);
                calls.pop();
            }
            else{
                sizes[curr]--;
                calls.push(adj[curr][sizes[curr]]);
                adj[curr].pop_back();
            }
        }
        for(int i = 0; i<n-1;i++){
            cout << 0;
        }
        path.pop();
        while(!path.empty()){
            cout << path.top() % 2;path.pop();
        }
        cout << "\n";
    }
    else cout << "01\n";
}