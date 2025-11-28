#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;

int main(){
    int n,k; cin >> n >> k;
    map<int,int> count;
    priority_queue<pi> pq;
    int x;
    queue<int> q;
    for(int i = 0; i<k; i++){
        cin >> x;
        count[x]++;
        q.push(x);
    }
    for(auto e: count){
        pq.push({e.S, -e.F});
    }
    for(int i = k; i<=n; i++){
        cout << -pq.top().S << " ";
        cout << flush; 
        pq.push({(--count[q.front()]),-q.front()});
        q.pop();
        cin >> x;
        count[x]++; 
        pq.push({count[x],-x});
        q.push(x);
        while(!pq.empty() && (pq.top().F != count[-pq.top().S])) pq.pop();
    }
}