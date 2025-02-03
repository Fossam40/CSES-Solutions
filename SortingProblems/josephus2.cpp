#include <bits/stdc++.h>
using namespace std;

void add(int* arr, int n, int k, int x){
    while(k<=n){
        assert(k>0);
        arr[k-1] += x;
        k += k&(-k);
    }
}

int sum(int* arr, int k){
    int s = 0;
    while(k>=1){
        s += arr[k-1];
        k -= k&(-k);
    }
    return s;
}

int sumr(int* arr, int s, int beg, int len){
    int end = ((beg - 2 + len) % s) + 1;
    if(beg <= end){
        return (sum(arr, end) - sum(arr, beg-1));
    }
    else if( beg - 1 == end){
        return sum(arr, s);
    }
    else{
        return sum(arr, s) - sumr(arr, s, end + 1, (beg - end) - 1);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n] = {};
    for(int i = 0; i< n; i++){
        add(arr, n, i+1, 1);
    }
    int it = 1;
    int t = k;
    for(int i = 0; i<n; i++) { // Remember to change limit to n
        int l = 0;
        t = k%(n-i);
        for(int b = n/2;b>0; b/=2){
            while(sumr(arr, n, it, b + l) <= t && (b+l) <=n){l += b;}
        }
        //cout << "Step: " << l + 1<< " (so next is not <2) " << sumr(arr,n,it,l + 1) <<" \n";
        it = ((it - 1+ l) % n) + 1;
        printf("%d ", it);
        add(arr, n, it, -1);
    }  
}