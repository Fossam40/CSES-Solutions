#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i<t; i++){
        int n, s1, s2; cin >> n >> s1 >> s2;
        if((s1+s2 <= n) && (min(s1,s2)!=0 || max(s1,s2)==0)){
            vector<int> p1(n);
            vector<int> p2(n);
            for(int i = 0; i< n-(s1+s2); i++ ){
                p1[n-i-1] = n-i; p2[n-i-1] = n-i;
            }
            n = s1 + s2;
                for(int i = 0; i<s1; i++){
                    p1[i] = n-i; p2[i] = s1-i;
                }
                for(int i = s1; i<s1+s2; i++){
                    p2[i] = n-(i-s1); p1[i] = n-i;
                }
            cout << "YES\n";
            for(auto u: p1) cout << u << " ";
            cout << "\n";
            for(auto u: p2) cout << u << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
}