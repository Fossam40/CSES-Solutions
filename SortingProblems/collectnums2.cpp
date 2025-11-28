#include <bits/stdc++.h>
using namespace std;

int calc(int* arr, int s, int e){
    int p = arr[s];
    int c = 1;
    for(int i = s; i<e; i++){
        c += (arr[i]<p);
        p = arr[i];
    }
    return c;
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
    int ori[n];
    for(int i = 0; i < n; i++){
        cin >> ori[i];
        arr[ori[i] - 1] = i;
    }
    int c = calc(arr, 0, n);
    int t;
    int x,y,tmp;
    for(int i = 0; i< m; i++){
        cin >> x >> y;
        x--;
        y--;
        t = 0;
        if(abs(ori[x] -ori[y] ) <= 2){
            t = calc(arr, max(0,min(ori[x],ori[y])-2), max(ori[x],ori[y]) + 1);
            tmp = ori[x];
            ori[x] = ori[y];
            ori[y] = tmp;
            arr[ori[x] - 1] = x;
            arr[ori[y] - 1] = y;
            t -= calc(arr, max(0,min(ori[x],ori[y])-2), max(ori[x],ori[y]) + 1);

        }
        else{
            t = calc(arr, max(0,ori[x]-2), ori[x] + 1);
            t += calc(arr, max(0,ori[y]-2), ori[y] + 1);
            tmp = ori[x];
            ori[x] = ori[y];
            ori[y] = tmp;
            arr[ori[x] - 1] = x;
            arr[ori[y] - 1] = y;
            t -= calc(arr, max(0,ori[x]-2), ori[x] + 1);
            t -= calc(arr, max(0,ori[y]-2), ori[y] + 1);
        }
        c -= t;
        cout << c << "\n";
    }
}