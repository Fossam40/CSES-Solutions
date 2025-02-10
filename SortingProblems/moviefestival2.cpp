#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;


int main(){
    multiset<int> pq;
    int n,k;
    cin >> n >> k;
    int members = 1;
    int movs = 1;
    pi arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i].S >> arr[i].F;
    }
    sort(arr, arr+n);
    pq.insert(arr[0].F);
    for(int i = 1; i<n; i++){
        auto cand = pq.upper_bound(arr[i].S);
        if(cand != pq.begin() ){
            cand--;
            pq.erase(cand);
            pq.insert(arr[i].F);
            movs++;
        }
        else if(members < k){
            pq.insert(arr[i].F);
            movs++;
            members++;
        }
    }
    cout << movs << "\n";
}