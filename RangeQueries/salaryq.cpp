#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> pi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> iset;
#define F first
#define S second

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n, q, x, y;
    char c;
    unordered_map<int,int> m;
    iset s;
    scanf("%d %d", &n, &q);
    for(int i = 1; i<=n; i++){
        cin >> x;
        m[i] = x;
        s.insert({x,i});
    }
    for(int i = 0; i<q; i++){
        scanf(" %c %d %d", &c, &x, &y);
        if(c == (int)'!'){
            int sal = m[x];
            auto e = s.find({sal,x});
            s.erase(e);
            s.insert({y, x});
            m[x] = y;
        }
        else{
            auto b = s.lower_bound({x,0});
            auto e = --(s.upper_bound({y,n}));
            if(b != s.end()){
                int beg = s.order_of_key(*b);
                int end = s.order_of_key(*e);
                printf("%d\n",end - beg + 1 );
            }
            else{
                printf("0\n");
            }
        }
    }
}