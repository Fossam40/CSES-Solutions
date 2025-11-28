#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define S second
#define F first

void update(vi& vals, int pos){
    while(pos < vals.size()){
        vals[pos]+=1;
        pos += pos&(-pos);
    }
}

int sum(vi & vals, int pos){
    int ans = 0;
    while(pos>0){
        ans += vals[pos];
        pos -= pos&(-pos);
    }
    return ans;
}

int main(){
    srand((unsigned)time(0)); 
    int decal;
    decal = (rand()%100000)+1; 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<vector<pi>> queries(n+1);
    vi ans(q,0);
    vi oldnums(n);
    vi nums;
    for(int i = 0; i<n; i++){
        cin >> oldnums[i];
        oldnums[i]+=decal;
        nums.push_back(oldnums[i]);
    }
    int a,b,c,d;
    for(int i =0; i<q; i++){
        cin >> a >> b >> c >> d;
        c+=decal;d+=decal;
        nums.insert(nums.end(), {c,d,c-1});
        queries[b-1].push_back({d, i});
        queries[b].push_back({-(c-1), i});
        queries[a-1].push_back({-d, i});
        if(a>1) queries[a-2].push_back({c-1, i});
    }
    sort(nums.begin(), nums.end());
    unordered_map<int,int> f;
    int j = 0;
    int len = 1;
    int prev = -1;
    while(j<nums.size()){
        prev = nums[j];
        while(j<nums.size() && prev == nums[j]) j++;
        f[prev] = len;
        len++;
    }
    vi vals(len,0);
    for(int i = 0; i<(n+1); i++){
        for(auto e: queries[i]){
            if(e.F > 0){
                ans[e.S] += sum(vals, f[e.F]) + (oldnums[i]<=e.F);

            }
            else{
                ans[e.S] -= sum(vals, f[-e.F]);
            }
        }
        if(i<n) {
            update(vals, f[oldnums[i]]);
        }
    }
    for(int i = 0; i<q; i++){
        cout << ans[i] << "\n";
    }
}