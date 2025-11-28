#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for(int i = 0; i<n; i++) cin >> arr1[i];
    for(int i = 0; i<m; i++) cin >> arr2[i];
    vector<vector<int>> dp(n, vector<int>(m+1,0)); 
    int maxi = 0;
    int i_max = -1;
    int j_max = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dp[i][j+1] = dp[i][j];
            if(i>0) dp[i][j+1] = max(dp[i][j], dp[i-1][j+1]);
            if(arr1[i]==arr2[j]) {
                if(i>0) dp[i][j+1] = dp[i-1][j] + 1;
                else dp[i][j+1] = 1;
            }
            if(dp[i][j+1]>maxi){
                i_max = i;
                j_max = j+1;
                maxi = dp[i][j+1];
            }
        }
    }
    
    if(i_max != -1){
        stack<int> seq;
        while(i_max>=0){
            if(i_max>0 && dp[i_max-1][j_max]== dp[i_max][j_max]){
                i_max--;
            }
            else if(j_max > 0 && (dp[i_max][j_max-1])== dp[i_max][j_max]) j_max--;
            else if(j_max>0 && i_max>0 && (dp[i_max-1][j_max-1]+1)== dp[i_max][j_max]){
                seq.push(arr1[i_max]);
                j_max--;
                i_max--;
            }
            else if(i_max==0 && dp[i_max][j_max]==1){
                seq.push(arr1[0]);
                break;
            }
            else{
                i_max--;
            }
        }
        cout << maxi << endl;
        while(!seq.empty()) {cout << seq.top() << " "; seq.pop();}
        
    }
    else cout << "0\n";
}