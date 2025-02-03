#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> d;
    set<int> l;
    int n,m,x;
    scanf("%d %d", &n, &m);
    l.insert(0);
    l.insert(n);
    d.insert(n);
    for(int i = 0; i<m; i++){
        scanf("%d", &x);
        auto p = l.lower_bound(x);
        auto n = p;
        if(p != l.begin()){p--;}
        d.erase(d.find(*n - *p));
        l.insert(x);
        d.insert(x - *p);
        d.insert(*n - x);
        printf("%d ", *(--d.end()));
    }
}