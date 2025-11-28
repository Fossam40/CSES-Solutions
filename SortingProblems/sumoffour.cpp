#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    pi arr[n];
    for(ll i = 0; i< n; i++){
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr, arr+n);
    bool found = false;
    int i;
    int pt1;
    int pt2;
    int j;
    int s;
    for(i = 0; i<n; i++){
        for(j = i+1; j<n; j++){
            if(found){break;}
            if(arr[i].F + arr[j].F > x){break;}
            pt1 = i+1;
            pt2 = j-1;
            while(pt1 < pt2){
                if(pt1 == i || pt1 == j){pt1++;}
                else if(pt2 == i|| pt2 == j){pt2--;}
                else{
                    if(arr[j].F + arr[i].F +arr[pt1].F + arr[pt2].F <  x){
                        pt1++;
                    }
                    else if(arr[j].F + arr[i].F + arr[pt1].F + arr[pt2].F > x){
                        pt2--;
                    }
                    else {
                        found = true;
                        cout << arr[j].S + 1 << " " << arr[i].S + 1 << " " << arr[pt1].S + 1 << " " << arr[pt2].S + 1 << "\n";
                        break;
                    }
                }
            }
        }
    }
    if(!found){
        cout << "IMPOSSIBLE\n";
    }
}