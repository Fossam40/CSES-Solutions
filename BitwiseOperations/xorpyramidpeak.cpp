#include <bits/stdc++.h>
using namespace std;
#define N 200000
vector<int> arr(N);

int cuttree(int start, int size){
    int logn = 31 - __builtin_clz(size);
    int full = (1<<logn);
    if(full == size){
        int ans = 0;
        for(int i = 0; i<size; i++){
            ans ^= arr[start+i];
        }
        return ans;
    }
    return cuttree(start, size-full) ^ cuttree(start + full, size - full);
}

int main(){
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout << cuttree(0,n) << "\n";
}