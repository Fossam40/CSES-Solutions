#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k,n; 
    scanf("%lld %lld",&n, &k);
    ll x, a, b, c; 
    scanf("%lld %lld %lld %lld",&x, &a, &b, &c);
    int arr[30] = {0};
    int* list = (int*)malloc(sizeof(int)*k);
    int beg = 0;
    int tot = 0;
    int sum = 0;
    int j;
    int ix = x;
    for(int i = 0; i<k; i++){
        list[i] = ix;
        sum |= ix;
        j = __builtin_ctz(ix);
        while(ix != 0 && j<30){
            arr[j]++;
            ix = ix ^(1<<j);
            j = __builtin_ctz(ix);
        }
        x = (a*x + b) % c;
        ix = x;
    }
    tot = sum;
    for(int i = k; i<n; i++){
        int y  = list[beg]^(list[beg]&ix);
        int yu = list[beg];
        j = __builtin_ctz(y);
        while(y != 0 && j<30){
            arr[j]--;
            y = y ^(1<<j);
            if(arr[j]==0) sum ^= (1<<j);
            j = __builtin_ctz(y);
        }
        list[beg]=ix;
        ix = ix^(yu&ix);
        beg++; if(beg == k) beg = 0;
        sum |= ix;
        j = __builtin_ctz(ix);
        while(ix != 0 && j<30){
            arr[j]++;
            ix = ix ^(1<<j);
            j = __builtin_ctz(ix);
        }
        x = (a*x + b) % c; ix = x;
        tot ^= sum;
    }
    printf("%d\n", tot);
}