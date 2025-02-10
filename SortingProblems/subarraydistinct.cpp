#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x,k;
    map<int,int> m;
    cin >> n >> k;
    int arr[n];
    int d = 0;
    long long c = 0;
    int p = 0;
    for(int i= 0; i< n; i++){
        cin >> x;
        arr[i] = x;
        if(m.count(x) && m[x] != 0){
            m[x]++;
            c += i+1 - p;
        }
        else{
            m[x] = 1;
            d++;
            if(d == k + 1){
                while(m[arr[p]] != 1){
                    m[arr[p]]--;
                    p++;
                }
                m[arr[p]]--;
                p++;
                d--;
            }
            c+= i+1-p;
        }
    }
    cout << c << "\n";
}