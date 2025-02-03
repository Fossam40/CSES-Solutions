#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i< n; i++){
        s.insert(i+1);
    }
    auto i = s.begin();
    
    while(s.size() > 0){
        if(i == s.end()){ i = s.begin();}
        auto d = ++i;
        if(d == s.end()){ d = s.begin(); i = d;}
        i++;
        cout << *d << " ";
        s.erase(d);
    }
}