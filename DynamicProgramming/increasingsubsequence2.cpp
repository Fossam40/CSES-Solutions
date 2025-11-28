#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C (ll)(1e9 + 7)

void updt(vl & fw, int a, int b){
    while(a<=(fw.size()-1)){
        fw[a] =(fw[a] + b) % C;
        a += a&-a;
    }
}

ll gets(vl& fw, int a){
    ll ans = 0;
    while(a>=1){
        ans = (ans + fw[a]) % C;
        a -= a&-a;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<pl> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr.begin(), arr.end());
    vector<ll> fw(n+1,0);
    int j = 0;
    int prev = arr[0].F;
    while(j<n){
        stack<pl> todo;
        while(j<n && arr[j].F== prev){
            todo.push({arr[j].S, (1 + gets(fw, arr[j].S))%C});
            j++;
        }
        while(!todo.empty()){
            updt(fw, todo.top().F + 1, todo.top().S); 
            todo.pop();
        }
        prev = arr[j].F;
    }
    cout << gets(fw, n) << "\n";
}