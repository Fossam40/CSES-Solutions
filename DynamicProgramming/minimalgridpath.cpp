#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second

int main(){
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n,'a'));
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<n; j++){
            grid[i][j] = s[j];
        }
    }
    queue<pair<pi,pair<int,char>>> q;
    q.push({{0,0},{0,'a'}});
    vector<char> ans(2*n-1, 'Z');
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    while(!q.empty()){
        int x,y,d; char p;
        tie(x,y) = q.front().F; 
        tie(d,p) = q.front().S;q.pop();
        if(!visited[x][y]){
            if(d==0 || ans[d-1]==p){
                visited[x][y] = true;
                if(grid[x][y]<=ans[d]){ // lazy, can improve
                    ans[d] = grid[x][y];
                    if(x<n-1) q.push({{x+1,y},{d+1, grid[x][y]}});
                    if(y<n-1) q.push({{x,y+1},{d+1, grid[x][y]}});
                }
            }
        }
    }
    for(auto u: ans) cout << u;
    cout <<"\n";
}