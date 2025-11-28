#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    queue<int> q;
    set<int> s;
    q.push(arr[0]);
    s.insert(arr[0]);
    ll total = 1;
    for(int i = 1; i<n; i++){
        if(s.count(arr[i])){
            while(q.front() != arr[i]){
                s.erase(q.front());
                q.pop();
                total += q.size();
            }
            total += q.size();
            q.pop();
        }
        else{
            total++;
        }
        q.push(arr[i]);
        s.insert(arr[i]);
    }
    q.pop();
    total += (q.size())*(q.size() + 1)/2;
    cout << total << "\n";
}
