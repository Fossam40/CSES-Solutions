#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll nbpaths(vector<vi> & adj, vi & nums, int curr){
    if(nums[curr] == -1){
        ll cpaths = 0;
        for(auto u: adj[curr]) cpaths = (cpaths + nbpaths(adj, nums, u)) % (ll)(1e9 + 7);
        nums[curr] = max((ll)0, cpaths);
    }
    return nums[curr];
}


int main(){
    int n,m;
    cin >> n >> m;
    int a,b;
    vector<vi> adj(n);
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    vi nums(n, -1);
    nums[n-1] = 1;
    nbpaths(adj, nums, 0);
    cout << nums[0] << "\n";
}