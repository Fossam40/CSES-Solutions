#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ll n,x;
    cin >> n >> x;
    int k;
    vector<pair<ll,int>> nums;
    for(int i = 0; i< n; i++){
        cin >> k;
        nums.push_back({k,i});
    }
    int l = 0;
    int r = n-1;
    sort(nums.begin(), nums.end());
    while((r>l) && (nums[r].F + nums[l].F != x)){
        if(nums[r].F + nums[l].F > x){
            r--;
        }
        else{
            l++;
        }
    }
    if((r > l)){
        cout << nums[l].S + 1<< " " << nums[r].S  + 1<< "\n";
    }
    else{
        cout <<"IMPOSSIBLE\n";
    }
}