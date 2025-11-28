#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> m;
    m[1] = 2;
    m[1] = 0;
    m.erase(1);
    if(!m.empty()) cout << (*m.begin()).first << "\n";
}