#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    set<pi> s;
    queue<pi> q;
    int arr[n];
    ll sum_end = 0;
    ll sum_beg = 0;
    ll m = -1e18;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        sum_end += arr[i];
        if(i>=(a-1)){
            s.insert({sum_beg,i});
            q.push({sum_beg,i});
            if(i>=b){
                s.erase(q.front());
                q.pop();
            }
            if(s.size() != 0){
                auto b = s.begin();
                m = max(m,sum_end - (*b).first);
            }
            else{
                m = max(m, sum_end - sum_beg);
            }
            sum_beg += arr[i-(a-1)];
        }
    }
    cout << m << "\n";
}