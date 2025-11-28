#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;

int main(){
    int n; cin >> n;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> grid(n, vector<int>(n, (int)(1e9)));
    queue<pair<pi,int>> q;
    q.push({{0,0},0});
    pi arr[8] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    while(!q.empty()){
        int i = q.front().F.F; int j = q.front().F.S; int d = q.front().S; q.pop();
        if(!visited[i][j]){
            visited[i][j] = true;
            grid[i][j] = d;
            for(int k = 0; k<8; k++){
                int ip = i + arr[k].F;
                int jp = j + arr[k].S;
                if(ip>=0 && ip<n && jp>=0 && jp<n){
                    q.push({{ip,jp},d+1});
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