#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    set<int> comp;
    for(int i = 0; i<=n; i++){
        comp.insert(i);
    }
    map<int,int> currCount;
    queue<int> q;
    int x;
    for(int i = 0; i<k; i++){
        cin >> x;
        comp.erase(x);
        q.push(x);
        currCount[x]++;
    }
    for(int i = k; i<=n; i++){
        cout << *(comp.begin()) << " ";
        cout << flush;
        cin >> x;
        if(currCount[q.front()]==1) comp.insert(q.front());
        currCount[q.front()]--;
        q.pop();
        q.push(x);
        currCount[x]++;
        comp.erase(x);
    }
}