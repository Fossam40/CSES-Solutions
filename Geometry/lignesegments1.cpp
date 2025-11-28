#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;

#define F first
#define S second

ll surpass(pl f1, pl f2){
    return max((double)0, ceil((double)(f1.S - f2.S)/(double)(f2.F - f1.F)));
}
 

int main() {
    ll n,m; cin >> n >> m;
    vector<pl> lines(n);
    ll y1,y2;
    for(int i = 0; i<n; i++){
        cin >> y1 >> y2;
        lines[i] = {(y2-y1)/m, -y1};
    }
    sort(lines.begin(), lines.end());
    vector<pair<pl,pl>> partition;
    ll pred_slope = (1e18);
    for(int i = 0; i<n; i++){
        lines[i].S = -lines[i].S;
        if(lines[i].F == pred_slope) continue;
        if(partition.size()==0) partition.push_back({{0,m},lines[i]});
        if((lines[i].F*m + lines[i].S) <= (partition[partition.size()-1].S.F*m + partition[partition.size()-1].S.S)) continue;
        int incrust = -1;
        pred_slope = lines[i].F;
        for(int j = partition.size(); j>0; j/=2){
            while((j+incrust < (int)partition.size()) && surpass(lines[i], partition[j+incrust].S)>= partition[j+incrust].F.F){
                incrust += j;
            }
        }
        
        while(partition.size()>(incrust +1 )){
            partition.pop_back();
        }
        if(partition[incrust].F.F == surpass(lines[i], partition[incrust].S)){
            int cx = partition[incrust].F.F;
            partition.pop_back();
            partition.push_back({{cx,m}, lines[i]});
        }
        else{
            partition[incrust].F.S = surpass(lines[i], partition[incrust].S)-1;
            partition.push_back({{surpass(lines[i], partition[incrust].S),m}, lines[i]});
        }
    }
    int i = 0;
    for(int j = 0; j<=m; j++){
        if(partition[i].F.S < j) i++;
        cout << partition[i].S.F*j + partition[i].S.S << " ";
    }
    cout << "\n";
}