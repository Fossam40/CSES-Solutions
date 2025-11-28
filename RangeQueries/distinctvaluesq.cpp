#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,pair<int,int>> qi; //<segment, end, begin, i>
#define S second
#define F first
int main(){
    int n, q, x, y;
    scanf("%d %d", &n, &q);
    int segments = (int)sqrt(n + 0.) + 1;
    vector<pair<int,int>> comp(n);
    vector<int> arr(n);
    vector<qi> que(q);
    for(int i = 0; i<n; i++){
        scanf("%d",&x);
        comp[i] = {x,i};
    }
    sort(comp.begin(), comp.end());
    int i = 0;
    int repl = 0;
    while(i<n){
        int prev = comp[i].F;
        while(comp[i].F == prev){
            prev = comp[i].F;
            arr[comp[i].S] = repl;
            i++;
        }
        repl++;
    }
    vector<int> freq(repl + 1,0);
    for(int i = 0; i<q; i++){
        scanf("%d %d", &x, &y);
        que[i] = {{(x-1)/segments, y-1},{x-1, i}};
    }
    sort(que.begin(), que.end());
    freq[arr[0]] = 1;
    vector<pair<int,int>> ans(q);
    int g = 0;
    int d = 0;
    int distinct = 1;
    for(int tr = 0; tr<q; tr++){
        while(d<que[tr].F.S){
            d++;
            if((freq[arr[d]]++)==0) distinct++;
        }
        while(d>que[tr].F.S){
            if((--freq[arr[d--]])==0) distinct--;
        }
        while(g<que[tr].S.F){
            if((--freq[arr[g++]])==0) distinct--;
        }
        while(g>que[tr].S.F){
            g--;
            if((freq[arr[g]]++)==0) distinct++;
        }
        ans[tr].F = que[tr].S.S;
        ans[tr].S = distinct;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i<q; i++){
        printf("%d\n",ans[i].S);
    }
}