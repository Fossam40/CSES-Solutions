#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n,0));
    vector<int> found(2*n + 2, -1);
    int next = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            next++;
            for(int k = i-1; k>=0; k--){
                found[grid[k][j]] = next;
            }
            for(int k = j-1; k>=0; k--){
                found[grid[i][k]] = next;
            }
            for(int k = 0; k< 2*(n+1); k++){
                if(found[k]!= next){
                    grid[i][j] = k;
                    break;
                }
            }
        }
    }
    for(auto a: grid){
        for(auto b: a){
            cout << b << " ";
        }
        cout << "\n";
    }
}