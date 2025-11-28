#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void update_2d(vector<vi>& arr, int n, int x, int y, int diff){
    int ix = x;
    while(y<=n){
        x = ix;
        while(x<=n){
            arr[y][x] += diff;
            x += x&-x;
        }
        y += y&-y;
    }
}

int sum_2d(vector<vi>& arr, int n, int x, int y){
    int result = 0;
    int ix = x;
    while(y>=1){
        x = ix;
        while(x>=1){
            result += arr[y][x];
            x -= x&-x;
        }
        y -= y&-y;
    }
    return result;
}

int final_s(vector<vi>& arr, int n, int x1, int y1, int x2, int y2){
    int total = sum_2d(arr,n,y2,x2);
    return total - sum_2d(arr,n,y2,x1 - 1) - sum_2d(arr,n,y1-1, x2)+ sum_2d(arr,n,y1-1, x1-1);
}

int main(){ 
    int n, q;
    cin >> n >> q;
    string s;
    vector<vi> arr(n+1,vi(n+1,0));
    for(int i = 1; i<=n; i++){
        cin >> s;
        for(int j= 1; j<=n; j++){
            if(s[j-1]=='*') update_2d(arr, n, j, i, 1);
        }
    }
    int t, x1, y1, x2, y2;
    for(int i = 0; i<q; i++){
        cin >> t >> x1 >> y1;
        if(t==1){
            int prev = final_s(arr, n, x1, y1, x1, y1);
            update_2d(arr, n, y1, x1, 1 - 2*prev);
        }
        else{
            cin >> x2 >> y2;
            cout << final_s(arr, n, x1, y1, x2, y2) << "\n";
        }
    }
}