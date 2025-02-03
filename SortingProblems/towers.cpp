#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    multiset<int> t;
    int x;
    t.insert(1e9 + 1);
    for(int i = 0; i<n; i++){
        cin >> x;
        auto y = t.upper_bound(x);
        if(y == t.end()){
            t.insert(x);
        }
        else{
            t.erase(y);
            t.insert(x);
        }
    }
    cout << t.size() << "\n";
}