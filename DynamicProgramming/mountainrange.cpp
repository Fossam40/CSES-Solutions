#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second


int main(){
    int n; cin >> n;
    vector<pi> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i].F; arr[i].S = i;
    }
    stack<int> s;
    vector<pi> cands(n, {-1, -1});
    vector<int> dp(n,0);
    for(int i = 0; i<n; i++){
        while(!s.empty() && arr[s.top()].F<arr[i].F){
            if(cands[i].F == -1 || arr[cands[i].F].F<arr[s.top()].F) cands[s.top()].F = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i = n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()].F<arr[i].F){
            if(cands[i].S == -1 || arr[cands[i].S].F<arr[s.top()].F) cands[s.top()].S = i;
            s.pop();
        }
        s.push(i);
    }
    int maxsee = 1;
    sort(arr.begin(), arr.end());
    for(auto a: arr){
        dp[a.S]++;
        if(cands[a.S].S != -1){
            dp[cands[a.S].S] = max(dp[cands[a.S].S], dp[a.S]);
        }
        if(cands[a.S].F != -1){
            dp[cands[a.S].F] = max(dp[a.S], dp[cands[a.S].F]);
        }
        maxsee = max(maxsee, dp[a.S]);
    }
    cout << maxsee << "\n";
}
