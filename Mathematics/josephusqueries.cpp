#include <bits/stdc++.h>
using namespace std;

int josephus(int a, int b, bool odd){
    if(a==1) return 1;
    if(!odd && b<=(a/2)){
        return 2*b;
    }
    else if(odd && b<=((a+1)/2)){
        return 2*b - 1;
    }
    else{
        int diff = (a+odd)/2;
        if(a%2==0){
            return 2*josephus(a - diff, b-diff, odd)-!odd;
        }
        else{
            return 2*josephus(a - diff, b - diff, !odd)-!odd;
        }
    }
}

int main(){
    int q;
    cin >> q;
    int a,b;
    for(int i = 0; i<q; i++){
        cin >> a >> b;
        cout << josephus(a,b, false) << "\n";
    }
}