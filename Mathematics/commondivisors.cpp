#include <bits/stdc++.h>
using namespace std;

int decompose(int n, vector<int> & divs){
    int max_div = 1;
    for(int i = 1; (i*i)<=n; i++){
        if(n%i==0){
            divs[i]++;
            if(i*i != n) {
                divs[n/i]++;
            }
            if(divs[i]>=2) max_div = max(i, max_div);
            if(divs[n/i]>=2) max_div = max(n/i, max_div);
        }
    }
    return max_div;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> dev((int)(1e6 + 1),0);
    int x;
    int mfound = 1;
    for(int i = 0; i<n; i++){
        cin >> x;
        mfound = max(decompose(x, dev), mfound);
    }
    cout << mfound << "\n";
}