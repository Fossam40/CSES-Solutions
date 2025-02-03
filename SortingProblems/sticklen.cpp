#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vi it(n);
    vi s;
    int k;
    for(auto i: it){
        cin >> k;
        s.push_back(k);
    }
    sort(s.begin(), s.end());
    ll a = 0;
    ll o = s[(n-1)/2];
    for(auto i: s){
        a += abs(i - o);
    }
    cout << a << "\n";
}
