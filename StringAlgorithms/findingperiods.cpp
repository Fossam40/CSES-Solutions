#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int x = 0; int y = 0;
    vector<int> z(n);
    for(int i = 1; i<n; i++){
        z[i] = max(0,min(y-i+1, z[i-x]));
        while(z[i] + i < n && s[z[i]]==s[z[i]+i]){
            x = i; y = z[i] + i; z[i]++;
        }
    }
    for(int i = 1; i<n; i++){
        if(z[i]==(n-i)){
            cout << i << " ";
        }
    }
    cout << n << "\n";
}