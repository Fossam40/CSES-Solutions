#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, x;
    cin >> n >> x;
    int chi[n];
    for(int i = 0; i < n; i++){
        cin >> chi[i];
    }

    sort(chi, chi + n);
    int gond = 0;
    int light = 0;
    int heavy = n-1;
    while(light < heavy){
        if(chi[light] + chi[heavy] <= x){
            light++;
            heavy--;
        }
        else{
            heavy--;
        }
        gond++;
    }
    if(light == heavy){
        gond++;
    }
    cout << gond << "\n";
}