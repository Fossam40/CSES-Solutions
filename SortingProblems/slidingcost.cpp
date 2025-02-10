#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef pair<int,int> pi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> i_set;
typedef long long ll;
int main(){
    i_set s;
    int n,k, x;
    cin >> n >> k;
    int med = (k-1)/2;
    queue<pi> q;
    int obj;
    ll cost = 0;
    for(int i = 0; i< k; i++){
        cin >> x;
        s.insert({x,i});
        q.push({x,i});
    }
    obj = (*(s.find_by_order(med))).first;
    for(int i = 0; i< k; i++){
        cost += abs(obj - (q.front()).first);
        q.push(q.front());
        q.pop();
    }

    for(int i = 0; i< n - k; i++){
        cout << cost << " ";
        cin >> x;
        ll a = abs((q.front()).first - obj);
        cost -= abs((q.front()).first - obj);
        s.erase(q.front());
        q.pop();
        q.push({x,i+k});
        s.insert({x,i+k});
        int nob = (*(s.find_by_order(med))).first;
        cost = cost + abs(x-nob) ;
        if(nob > obj){
            cost = cost + (nob-obj)*(((k-1)/2)-(k/2));
        }
        else if(obj > nob){
            cost = cost  + (obj-nob)*((k/2)-((k-1)/2));
        }
        obj = nob;
    }
    cout << cost << " ";
}