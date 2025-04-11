#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pi;
typedef tree<pi, null_type, less<pi>,rb_tree_tag,tree_order_statistics_node_update> iset;

int main(){
    int n, x;
    cin >> n;
    iset s;
    for(int i = 0; i<n; i++){
        cin >> x;
        s.insert({i,x});
    }
    for(int i=0; i<n; i++){
        cin >> x;
        auto e = s.find_by_order(x - 1);
        cout << (*e).second << " ";
        s.erase(e);
    }
}