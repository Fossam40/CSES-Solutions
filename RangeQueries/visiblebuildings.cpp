#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define N 200001
int t[N] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    int builds[n];
    int decal[n] = {0};
    stack<pi> s;
    for(int i = 0; i<n; i++) cin >> builds[i];
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top().F<= builds[i]){
            decal[s.top().S] = i+1;
            s.pop();
        }
        s.push({builds[i], i});
    }
    int ans[q];
    vector<pair<pi,int>> queries(q);
    for(int i = 0; i<q; i++){
        cin >> queries[i].F.S >> queries[i].F.F;
        queries[i].S = i;       
    }
    sort(queries.begin(), queries.end());
    int currcheck = 0;
    for(int i = 0; i<q; i++){
        while(currcheck<queries[i].F.F){
            currcheck++;
            int a = decal[currcheck-1] + 1;
            while(a<N){
                t[a] += 1;
                a += a&(-a);
            }
            if(currcheck<(N-1)) {
                int a = currcheck + 1;
                while(a<N){
                    t[a] += -1;
                    a += a&(-a);
                }
            }
        }
        ans[queries[i].S] = 0;
        while(queries[i].F.S>0){
            ans[queries[i].S] += t[queries[i].F.S];
            queries[i].F.S -= queries[i].F.S&(-queries[i].F.S);
        }
    }
    for(int i = 0; i<q; i++) cout << ans[i] << "\n";
}
