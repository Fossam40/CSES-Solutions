#include <bits/stdc++.h>
using namespace std;

int main() {
    string m,s;
    cin >> m >> s;
    string fin = (s + "#") + m;
    int n = fin.size();
    int k = s.size();
    vector<int> z(n);
    int x = 0; int y = 0;
    for(int i = 1; i<n; i++){
        z[i] = max(0,min(y-i+1, z[i-x]));
        while(i + z[i] < n && fin[z[i]]==fin[i+z[i]]){
            x = i; y = i + z[i]; z[i]++;
        }
    }
    int count = 0;
    for(auto u: z){
        count += (u==k);
    }
    cout << count << "\n";
}