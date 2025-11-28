#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define int long long
ll arr[21];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    arr[0] = 1;
    for(int i = 1; i<21; i++){
        arr[i] = i* arr[i-1];
    }
    int t; cin >> t;
    for(int r = 0; r<t; r++){
        int type; cin >> type;
        if(type == 1){
            indexed_set s;
            ll n,k; cin >> n >> k;
            for(int i = 1; i<=n; i++){
                s.insert(i);
            }
            k--;
            for(int j = n-1; j>0; j--){
                int i = 0;
                while(k>=arr[j]){
                    i++;
                    k-=arr[j];
                }
                auto ans = s.find_by_order(i);
                cout << *ans << " ";
                s.erase(*ans);
            }
            while(!s.empty()){
                auto ans = s.find_by_order(0);
                cout << *ans << " ";
                s.erase(*ans);
            }
            cout << "\n";
        }
        else {
            indexed_set s;
            int n,x; cin >> n;
            for(int i = 1; i<=n; i++){
                s.insert(i);
            }
            ll k = 1;
            for(int i = 0; i<n; i++){
                cin >> x;
                int j = 0;
                while(x != *s.find_by_order(j))j++;
                k+= j*arr[n-1-i];
                s.erase(*s.find_by_order(j));
            }
            cout << k << "\n";
        }
    }
}