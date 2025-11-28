#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n);
    int x = 0; int y = 0;
    for(int i = 1; i<n;i++){
        z[i] = max(0, min(y-i+1,z[i-x]));
        while(z[i]+i < n && s[z[i]]==s[z[i]+i]){
            x = i; y = i + z[i]; z[i]++;
        }
    }
    for(int i = n-1; i>=1; i--){
        if(z[i]==(n-i)) cout << z[i] << " ";
    }
}