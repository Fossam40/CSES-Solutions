#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[1<<n][(1<<n) + 1]; //line,col = after,before
    for(int i = 0; i<(1<<n); i++){ // after
        int c = 0;
        for(int j = 0; j< (1<<n); j++){ // before
            arr[i][j] = 0;
            bool pending = false;
            for(int k = 0; k<n; k++){
                if(((i & j) != 0) || (pending && (((i&(1<<k)) != 0) || (j&(1<<k)) != 0) )){
                    pending = true;
                    break;
                }
                if(((i&(1<<k)) == 0) && pending){
                    pending = false;
                }
                else if(((i&(1<<k)) == 0) && !pending && ((j & (1<<k)) == 0)){
                    pending = true;
                }
                
            }
            if(!pending){
                arr[i][c] = j;
                c++;
            }
        }
        arr[i][c] = -1;
    }
    int* d[2];
    int a[(1<<n)] = {0};
    int b[(1<<n)];
    d[0] = a;
    d[1] = b;
    d[0][0] = 1;
    for(int k = 0; k<(m+1);k++){
        for(int i = 0; i<(1<<n); i++){
            d[(k+1)%2][i] = 0;
            int c = 0;
            while(arr[i][c] != -1){
                d[(k+1)%2][i] = (d[(k+1)%2][i] + d[k%2][arr[i][c]]) % (int)(1e9 + 7);
                c++;
            }
        }
    }
    cout << d[(m + 1)%2][(1<<n) - 1] << "\n";
}