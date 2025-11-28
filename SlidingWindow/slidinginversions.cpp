#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define F first
#define S second
typedef pair<int,int> pi;
typedef vector<int> vi;

void update(vi& fw, int pos, int q){
    while(pos<fw.size()){
        fw[pos] += q;
        pos += (pos&(-pos));
    }
}

int lowerthan(vi& fw, int pos){
    pos--;
    int ans = 0;
    while(pos>=1){
        ans += fw[pos];
        pos -= pos&(-pos);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    vector<pi> comp(n);
    queue<int> q;
    for(int i = 0; i<n; i++){
        cin >> comp[i].F;
        comp[i].S = i;
    }
    sort(comp.begin(), comp.end());
    int currcomp = 1;
    int prev = arr[0];
    for(int i = 0; i<n; i++){
        if(comp[i].F!=prev){
            currcomp++;
            prev = comp[i].F;
        }
        arr[comp[i].S] = currcomp;
    }
    ll ans = 0;
    vi fw(currcomp+1, 0);
    for(int i = 0; i<k; i++){
        q.push(arr[i]);
        update(fw, arr[i], 1);
        ans += (i +1 - lowerthan(fw, arr[i]+1));
    }
    cout << ans << " ";
    for(int i = k; i<n; i++){
        int prev = q.front(); q.pop();
        ans -= (lowerthan(fw, prev));
        update(fw, prev, -1);
        q.push(arr[i]);
        update(fw, arr[i], 1);
        ans += (k - lowerthan(fw, arr[i]+1));
        cout << ans << " ";
    }
    cout << "\n";
}