#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef pair<int,int> pi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> i_set;

int main(){
    i_set s;
    int n,k, x;
    cin >> n >> k;
    int med = (k-1)/2;
    queue<pi> q;
    for(int i = 0; i< k; i++){
        cin >> x;
        s.insert({x,i});
        q.push({x,i});
    }
    for(int i = 0; i< n - k; i++){
        cout << (*(s.find_by_order(med))).first << " ";
        cin >> x;
        s.erase(q.front());
        q.pop();
        q.push({x,i+k});
        s.insert({x,i+k});
    }
    cout << (*(s.find_by_order(med))).first << " ";
}
